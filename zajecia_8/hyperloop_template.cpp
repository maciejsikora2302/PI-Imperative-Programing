#include <iostream>

using namespace std;

typedef struct Node {
    int n;
    struct Node *next;
} Node;

void dfs(Node **graph, int *components, int n, int i, int component_no) {
    // traverse the graph and mark all nodes which belong to the component
    if (components[i] == -1){
        components[i] = component_no;
        for (Node *v = graph[i]; v != nullptr; v = v->next) {
            dfs(graph, components, n, v->n, component_no);

        }
    }
}

int *count_components(Node **graph, int n) {
    // this array shows to which component each node belongs
    // -1 means that node hasn't been visited yet
    int *components = new int[n];
    for (int i = 0; i < n; i++) components[i] = -1;
    // prepare components counter

    // in loop: find unvisited node, call DFS/BFS
    int component_no = 1;
    for (int i = 0; i < n; i++) {
        dfs(graph, components, n, i, component_no);
        component_no++;
    }

    return components;
}

int main() {
    int n, k, p;
    cin >> n;
    Node **graph = new Node *[n];
    for (int i = 0; i < n; i++) graph[i] = nullptr;
    cin >> k;
    cin >> p;
    for (int i = 0; i < k; i++) {
        Node *tmp1 = new Node, *tmp2 = new Node;
        int x, y;
        cin >> x;
        cin >> y;
        tmp1->n = y;
        tmp1->next = graph[x];
        graph[x] = tmp1;
        tmp2->n = x;
        tmp2->next = graph[y];
        graph[y] = tmp2;
    }
    int *components = count_components(graph, n);
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        cout << (components[x] == components[y] ? "TAK" : "NIE") << endl;
    }
}