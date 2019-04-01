#include <stdio.h>

int n;

void swap(int a,int b){
    int c=b;
    b=a;
    a=c;
}

int* my_first_sort(int tab[]) {



    int i, key, j;
    for(int i=1;i<n;i++){
        key =tab[i];
        j=i-1;

        while(j>=0 && tab[j]>key){
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=key;
    }
    return tab;
}

int main() {

    scanf("%d", &n);

    int *tab = NULL;
    tab = new int[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    int *res = my_first_sort(tab);

    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }

    delete[] tab;
}
