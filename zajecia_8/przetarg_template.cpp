#include <stdio.h>
// we're big guys now, let's use already implemeted list
// you might want check this out: http://www.cplusplus.com/reference/list/list/#functions
#include <list>

using namespace std;

// Global variables are bad, but in this case
// passing them in function would soon exceed memory limit.
// Trust me, I tried.
int n;
list<int> *graph;
int curr_list;
list<int> *lines;
bool is_euler;

void euler(int u,int start) {
    while (!graph[u].empty())
    {
        //bierzemy pierwszego sąsiada u
        //usuwamy obecnego wierzchołka z listy sąsiadów wybranego sąsiada
        int v = graph[u].front(); //sąsiad nazywa się v
        graph[v].remove(u); // siąsiadowi usuwamy krawędź prowadzącą do nas
        graph[u].pop_front(); // i usuwamy krawędź prowadzącą do sąsiada v

        euler(v,start); // wywołujemy rekurencyjnie dla sąsiada (robimy takiego dfs'a)
        if(graph[v].size()%2 == 1) break;
    }

    // add city to line
    if(u!=start){
        lines[curr_list].push_back(u);
    }
}

int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {

        int m, u, v;
        scanf("%d %d", &n, &m);

        graph = new list<int>[n + 2];
        lines = new list<int>[n + 2];

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        is_euler = true;
        curr_list=1;
        int start = 1;
        for (int i = 1; i <= n; i++) {
            // find starting city for euler
            // it must be a vertex with odd number of neighbours if it exists
            // or any one if every one has even degree
            if (graph[i].size() % 2 != 0) {
                if(curr_list==2) is_euler=false;
                euler(i, i);
                lines[curr_list].push_front(i);
                curr_list++;
            }
        }
        euler(start, start);
        lines[curr_list].push_front(start);

//        for (list<int>::iterator it = lines->begin(); it != lines->end(); it++) {
//            printf("%d ", *it);
//        }

        printf("%d\n", curr_list);
        for(int i=1;i<=n;i++){
            if(!lines[i].empty()){
                printf("%d ", lines[i].size());
//                for(int & it : lines[i]){
//                    printf("%d ", it);
//                }
            for(auto it = lines[i].begin();it!=lines[i].end();it++){
                printf("%d ", *it);
            }
                printf("\n");
            }
        }


        delete [] graph;
        delete lines;
    }
}
