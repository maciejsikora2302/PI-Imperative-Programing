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
list<int> *line;
int curr_list = 0;

void euler(int u) {
    while (!graph[u].empty())
    {
        int v = graph[u].front();// take first neighbour of u
        graph[u].pop_front();

        // iterate over neighbours of v
        // you can use list<int>::iterator it = graph[v].begin()
        // which makes "it" iterator (sth like pointer) pointing on first element of graph[v] list
        // iterator can be moved to next position like this: it++
        // and if you move it after last element of list it will be equal to graph[v].end()
        for (auto it = graph[v].begin();it!=graph[v].end();it++)
        {
            // if you find u remove it from list
            // you can access element pointed by iterator just like with pointer
            //printf("%d",*it);
            if (*it == u)
            {
                graph[v].erase(it);// use erase method
                break;
            }
        }

        euler(v);
        // recursively enter v
    }

    line->push_back(u);
    // add city to line

}

void euler_2(int u) {
    while (!graph[u].empty()) {

        int v = graph[u].front();// take first neighbour of u
        graph[u].pop_front();

        // iterate over neighbours of v
        // you can use list<int>::iterator it = graph[v].begin()
        // which makes "it" iterator (sth like pointer) pointing on first element of graph[v] list
        // iterator can be moved to next position like this: it++
        // and if you move it after last element of list it will be equal to graph[v].end()
        for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
            // if you find u remove it from list
            // you can access element pointed by iterator just like with pointer
            //printf("%d",*it);
            if (*it == u) {
                graph[v].erase(it);// use erase method
                break;
            }
        }

        euler_2(v);
        // recursively enter v
    }
//    if (u == n + 1) curr_list++;
//    if (u != n + 1)
        line->push_back(u);
    // add city to line

}

//int sub_seq_length(int it, int n) {
//    int sum = 0;
//    while (line[it].front() != n + 2) {
//        it++;
//        sum++;
//        if (line[it] == line[n + 3]) break;
//    }
//    return sum;
//}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int dl_podciagu(int tab[], int poz){
    int sum=0;
    while(tab[poz]!=n+1 and poz<line->size()){
        sum++;
        poz++;
    }
    return sum;
}

int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {

        int m, u, v;
        scanf("%d %d", &n, &m);

        graph = new list<int>[n + 3];
        line = new list<int>;

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int start = 1, counter=0;
        for (int i = 1; i <= n; i++) {
            // find starting city for euler
            // it must be a vertex with odd number of neighbours if it exists
            // or any one if every one has even degree
            if (graph[i].size() % 2 == 1) {
                graph[i].push_back(n + 1);
                graph[n + 1].push_back(i);
                start = i;
                counter++;
            }
        }
        if(counter>1){
            if (graph[start].empty()) {
                for (int i = start + 1; i <= n + 2; i++) {
                    if (!graph[i].empty()) {
                        start = i;
                        break;
                    }
                }
            }
            int line_numbers = max(graph[n + 1].size() / 2, 1);
            // start euler from correct city
            if(!graph[n+1].empty()) start=n+1;
            euler(start);
            printf("%d\n", line_numbers);
            int tab[line->size()+1];
            auto it=line->begin();
            for(int i=0;i<line->size();i++){
                tab[i]=*it;
//            printf("%d ",tab[i]);
                it++;
            }
//        printf("\n");
            for(int i=0;i<line->size();i++){
                if(tab[i]!= n+1){
                    printf("%d ", dl_podciagu(tab,i));
                    for(int j=i;j<line->size()-1;j++){
                        printf("%d ",tab[j]);
                        if(tab[j+1]==n+1 or j+2==line->size()){
                            i=++j;
                            printf("\n");
                            break;
                        }
                    }
                }
            }
//        for (int it = 1; it < line->size(); it++) {
//            if (!line[it].empty()) {
//                printf("%d ", line[it].size());
//                for (auto i = line[it].begin(); i != line[it].end(); i++) {
//                    printf("%d ", *i);
//                }
//                printf("\n");
//            }
//        }
//        for (int &it : *line) {
//            printf("%d ", it);
//        }
//        printf("\n");

            delete[] graph;
            delete line;
        }else{
            for (int i = 1; i <= n; i++)
            {
                // find starting city for euler
                // it must be a vertex with odd number of neighbours if it exists
                // or any one if every one has even degree
                if (graph[i].size()%2==1)
                {
                    start=i;
                }
            }


            // start euler from correct city
            euler(start);

            printf("1\n");
            printf("%lu ", line->size());
            for (list<int>::iterator it = line->begin(); it != line->end(); it++) {
                printf("%d ", *it);
            }
            printf("\n");

            delete [] graph;
            delete line;
        }

    }
}
