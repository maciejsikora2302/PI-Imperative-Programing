#include <stdio.h>
#include <stdlib.h>

int find_divider(int* tab, int n) {

   /***********************
    *  put your code here  *
    ***********************/
    for(int div=0;div<n;div++){
        int suma1=0,suma2=0;
        for(int i=0;i<div;i++) suma1+=tab[i];
        for(int i=div+1;i<n;i++) suma2+=tab[i];
        if(suma1==suma2) return div;
    }

}

int main() {
    int n;
    scanf("%d", &n);
    int* tab = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        scanf("%d", &tab[i]);
    }
    printf("%d\n", find_divider(tab, n));
    free(tab);
}
