#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_triangular(int **tab, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (tab[n - 1 - i][j] != 0) return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    /*****************************
    * allocate 2-dimensional tab *
    * and read values from input *
    *****************************/

    int **tab = malloc(n * sizeof(tab));
    for (int i = 0; i < n; i++) {
        tab[i] = malloc(n * sizeof(tab[i]));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int pom;
            scanf("%d", &pom);
            tab[i][j] = pom;
        }
    }

    printf(is_triangular(tab, n) ? "YES\n" : "NO\n");

    /**************
    * free memory *
    **************/

    for (int i = 0; i < n; i++) {
        free(tab[i]);
    }
    free(tab);
}