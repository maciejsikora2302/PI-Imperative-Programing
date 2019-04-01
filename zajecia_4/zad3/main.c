#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <iso646.h>


bool cyfry_maleja(int a) {
    int ostatnia_cyfra=a%10;
    a/=10;
    while (a > 0) {
        if(a%10>ostatnia_cyfra) return false;
        ostatnia_cyfra=a%10;
        a/=10;
    }
    return true;
}


int main() {
    int n;
    scanf("%d", &n);
    n++;
    bool *tab = malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            tab[i] = true;
        } else {
            tab[i] = false;
        }
    }
    tab[2] = true;
    for (int i = 3; i*i <= n; i += 2) {
        for (int j = i + i; j < n; j += i) {
            tab[j] = false;
        }
    }
    for (int i = 2; i < n; i++) {
        if (tab[i] and cyfry_maleja(i)) {
            printf("%d\n", i);
        }
    }
    free(tab);
    return 0;
}