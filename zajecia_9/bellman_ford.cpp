#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int INF = INT_MAX;

typedef struct Node {
    vector<pair<Node *, int>> neighbours;
    int val, dist;
} Node;

Node *newNode(int val) {
    Node *n = new Node;
    n->val = val;
    n->dist = INF;
    return n;
}

void addEdge(Node *u, Node *v, int w) {
    pair<Node *, int> edge(v, w);
    u->neighbours.push_back(edge);
}

void relax(Node *u, Node *v, int weight) {
    if (v->dist > u->dist + weight) {
        v->dist = u->dist + weight;
    }
}

bool bellmann_ford(Node **nodes, int n, Node *start) {
    start->dist = 0;
    for (int k = 0; k < n ; ++k) {
        for (int i = 0; i < n; i++) {
            for (int v = 0; v < nodes[i]->neighbours.size(); v++) {
                relax(nodes[i], nodes[i]->neighbours[v].first, nodes[i]->neighbours[v].second);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < nodes[i]->neighbours.size(); v++) {
            if (nodes[i]->neighbours[v].first->dist > nodes[i]->dist + nodes[i]->neighbours[v].second) {
                return false;
            }
        }
    }
    return true;
    // put your code here
}

int main() {
    int N, k, start, end;
    cin >> N >> k;
    Node *nodes[N];
    for (int i = 0; i < N; i++) nodes[i] = newNode(i);

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(nodes[u], nodes[v], w);
    }

    cin >> start >> end;
    if (!bellmann_ford(nodes, N, nodes[start])) cout << "CYKL" << endl;
    else if (nodes[end]->dist < INF) cout << nodes[end]->dist << endl;
    else cout << "NIE" << endl;

    for (int i = 0; i < N; i++) delete nodes[i];
}
