#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
} node;

node* reverse(node* list) {

    /***********************
    *  put your code here  *
    ***********************/
    node* next = NULL;
    node* prev = NULL;
    while(list != NULL){
        next = list->next;
        list->next=prev;
        prev=list;
        list=next;
    }
    return prev;
}

int main() {
    int n;
    int val;
    scanf("%d", &n);
    node* list = malloc(sizeof(node));
    list->next = NULL;
    node* tmp = list;
    for (int i=0; i<n; i++) {
        scanf("%d", &val);
        tmp->next = malloc(sizeof(node));
        tmp = tmp->next;
        tmp->value = val;
        tmp->next = NULL;
    }
    tmp = list->next;
    free(list);

    list = reverse(tmp);

    node* tmp2;

    while(list != NULL) {
        printf("%d\n", list->value);
        /****************************
        * remember - remove garbage *
        ****************************/

        tmp2=list->next;
        free(list);
        list=tmp2;
    }
}
