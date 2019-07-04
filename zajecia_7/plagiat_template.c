#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_TEXT_LENGTH = 200;

int min(int a, int b) {
    if (a <= b) return a;
    return b;
}

int distance(char *a, int a_length, char *b, int b_length) {

//    if(a[0]=='\0') return b_length;
//    if(b[0]=='\0') return a_length;
//    int tab[a_length + 1][b_length + 1];
//    a_length++;
//    b_length++;
    int** tab = malloc((a_length+1)*sizeof(int));

    for (int i = 0; i <= a_length; i++) {
        tab[i] = malloc((b_length+1)*sizeof(int));
        for (int j = 0; j <= b_length; j++) {
            tab[i][j] = 0;
        }
    }
    for (int i = 1; i <= a_length; i++)tab[i][0] = i;
    for (int i = 1; i <= b_length; i++)tab[0][i] = i;
    int substitution_cost;
//    b_length--;
//    a_length--;
    for (int j = 1; j <= b_length; j++) {
        for (int i = 1; i <= a_length; i++) {
            if (a[i - 1] == b[j - 1]) {
                substitution_cost = 0;
            } else {
                substitution_cost = 1;
            }
//            printf("%d %d %d\n", tab[i-1][j], tab[i][j-1],tab[i-1][j-1]);
            tab[i][j] = min(tab[i - 1][j] + 1,
                            min(tab[i][j - 1] + 1,
                                tab[i - 1][j - 1] + substitution_cost));
        }
    }

    return tab[a_length][b_length];
}

int main() {
    char *a = malloc(MAX_TEXT_LENGTH * sizeof(char));
    char *b = malloc(MAX_TEXT_LENGTH * sizeof(char));
    a[0]=0;
    b[0]=0;
    scanf("%[^\n]", a);
    scanf("%c\n", b); // reads \n
    scanf("%[^\n]", b);
    if(strlen(a)== 0){
        printf("%d\n", strlen(b));
        return 0;
    }
    if(strlen(b) == 0){
        printf("%d\n", strlen(a));
        return 0;
    }
//    if(a[0]==' '){
//        printf("%d\n", strlen(b)-1);
//        return 0;
//    }
    printf("%d\n", distance(a, strlen(a), b, strlen(b)));
}