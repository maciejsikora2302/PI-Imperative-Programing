#include <stdio.h>
#include <stdlib.h>

void encrypt(char* message, int n) {

    /***********************
    *  put your code here  *
    ***********************/
    int shift=0;
    while(message[shift]!=' ' && shift<n){
        shift++;
    }
    //modeulo 26
    for(int i=0;i<n;i++){
        if(message[i]==' ') continue;
        if(message[i]+shift>122){
            message[i]+=shift-26;
        }else{
            message[i]+=shift;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char* message = (char*) malloc((n+1) * sizeof(char));
    fgets(message, n+1, stdin); // reads \n
    fgets(message, n+1, stdin);
    encrypt(message, n);
    printf("%s\n", message);
    free(message);
}
