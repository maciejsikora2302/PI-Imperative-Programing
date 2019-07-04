#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX / 2;

typedef struct Segment {
    int town, travel_time;
} Segment;

typedef struct Line {
    Segment *segments;
    int number, length, start_town;
} Line;

Line *newLine(int number, int length, int start_town) {
    Line *l = new Line;
    l->number = number;
    l->length = length;
    l->start_town = start_town;
    l->segments = new Segment[length];
    return l;
}

typedef struct Node {
    int town, id;
    vector<pair<Node *, int> > neighbours;
} Node;

int **calculateTimesMatrix(Line **lines, int lines_no, int towns) {
    int **tab = new int*[towns];
    for (int i = 0; i < towns; i++) {
        tab[i] = new int[towns];
    }
    for (int j = 0; j < towns; ++j) {
        for (int i = 0; i < towns; ++i) {
            tab[j][i]=INF;
        }
        tab[j][j]=0;
    }
    for(int i=0;i<lines_no;i++){
        int from=lines[i]->start_town;
        for(int j=0;j<lines[i]->length;j++){
            int to=lines[i]->segments[j].town;
            tab[from][to]=min(lines[i]->segments[j].travel_time,tab[from][to]);
            tab[to][from]=min(lines[i]->segments[j].travel_time,tab[from][to]);
            from=to;
        }
    }
    for(int k=0;k<towns;k++){
//        int pom[towns][towns];
//        for(int i=0;i<towns;i++){
//            for(int j=0;j<towns;j++){
//                pom[i][j]=tab[i][j];
//            }
//        }
        for(int i=0;i<towns;i++){
            for(int j=0;j<towns;j++){
                tab[i][j]=min(tab[i][j],tab[i][k]+tab[k][j]);
            }
        }
//        for(int i=0;i<towns;i++){
//            for(int j=0;j<towns;j++){
//                tab[i][j]=pom[i][j];
//            }
//        }
    }
    return tab;
}

int main() {
    int towns, lines_no, queries;
    cin >> towns >> lines_no >> queries;
    Line **lines = new Line *[lines_no];
    for (int i = 0; i < lines_no; i++) {
        int len, start;
        cin >> len >> start;
        lines[i] = newLine(i, len - 1, start);
        for (int j = 0; j < len - 1; j++) {
            int next, time;
            cin >> time >> next;
            lines[i]->segments[j].town = next;
            lines[i]->segments[j].travel_time = time;
        }
    }

    int **times = calculateTimesMatrix(lines, lines_no, towns);

    for (int i = 0; i < queries; i++) {
        int u, v;
        cin >> u >> v;
        cout << times[u][v] << endl;
    }

    for (int i = 0; i < towns; i++) delete[] times[i];
    delete[] times;
    for (int i = 0; i < lines_no; i++) {
        delete[] lines[i]->segments;
        delete lines[i];
    }
    delete[] lines;
}

