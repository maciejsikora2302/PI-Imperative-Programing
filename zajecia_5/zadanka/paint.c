#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point {
    int x, y;
} point;

typedef struct queue {
    int start, end, size;
    point **elements;
} queue;

/****************************
* implement functions below *
****************************/

queue *new_queue(int size) {
    queue *q = malloc(sizeof(queue));
    q->start = 0;
    q->end = 0;
    q->size = size;
    q->elements = malloc(size * sizeof(point));
    return q;
}

void delete_queue(queue *q) {
    free(q->elements);
    free(q);
}

void put(queue *q, point *value) {
    q->elements[q->end] = value;
    q->end++;
}

point *get(queue *q) {
    q->start++;
    return q->elements[q->start - 1];
}

bool is_empty(queue *q) {
    return q->start == q->end;
}

void fill(int **image, int n, int x, int y, int color) {
    queue *points = new_queue(n * n);
    // put first point
    point *a = malloc(sizeof(point *));
    a->x = x;
    a->y = y;
    put(points, a);
    while (!is_empty(points)) {
        // add your code here
        point *b = get(points);
        image[b->x][b->y] = color;
        int X = b->x, Y = b->y;
        free(b);
        X++;
        if (X >= 0 && Y >= 0 && X < n && Y < n && image[X][Y] == 0){
            point* p= malloc(sizeof(point*));
            p->x=X;
            p->y=Y;
            put(points, p);
        }
        X -= 2;
        if (X >= 0 && Y >= 0 && X < n && Y < n && image[X][Y] == 0){
            point* p= malloc(sizeof(point*));
            p->x=X;
            p->y=Y;
            put(points, p);
        }
        X++;
        Y++;
        if (X >= 0 && Y >= 0 && X < n && Y < n && image[X][Y] == 0){
            point* p= malloc(sizeof(point*));
            p->x=X;
            p->y=Y;
            put(points, p);
        }
        Y -= 2;
        if (X >= 0 && Y >= 0 && X < n && Y < n && image[X][Y] == 0){
            point* p= malloc(sizeof(point*));
            p->x=X;
            p->y=Y;
            put(points, p);
        }
    }
    delete_queue(points);
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int **image = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        image[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int x, y, color;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &color);
        fill(image, n, x, y, color);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
        free(image[i]);
    }
    free(image);
}