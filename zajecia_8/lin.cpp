#include <stdio.h>
#include <list>

using namespace std;

int n;
list<int> *graph;
int current_list;
list<int> *lines;
bool flag;


void euler(int u)
{
    while (!graph[u].empty())
    {
        int v = graph[u].front();    
        graph[v].remove(u);
        graph[u].pop_front();
        euler(v);
    }
    
    if (!flag && u == 0)
        current_list++;
    else
        lines[current_list].push_back(u);
}

int main() {
    int Z;
    
    scanf("%d", &Z);
    
    while (Z--) {
        int m, u, v;
        scanf("%d %d", &n, &m);
        
        graph = new list<int>[n+2];
        lines = new list<int>[n+2];
        
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        flag = true;
        for(int i = 1; i <= n; i++)
            if(graph[i].size() % 2 != 0)
            {
                graph[i].push_back(0);
                graph[0].push_back(i);
                flag = false;
            }
        
        current_list = 0;
        
        if(flag)
            euler(1);
        else
            euler(0);
        
        int number_of_lines = 0;
        
        for(int i = 0; i <= current_list; i++)
            if(lines[i].size()>1)
                number_of_lines++;
        
        printf("%d\n", number_of_lines);
        
        for(int i = 0; i <= number_of_lines; i++)
        {
            if(lines[i].size() > 1)
            {
                printf("%lu ", lines[i].size());
                for (list<int>::iterator it = lines[i].begin(); it != lines[i].end(); it++)
                {
                    printf("%d ", *it);
                }
                printf("\n");
            }
        }
        
        delete[] graph;
        delete[] lines;
    }
}
