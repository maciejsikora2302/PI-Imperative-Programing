#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    int *elements;
    int top;
    int max_size;
} Stack;

/*****************************
* implements functions below *
*****************************/

void push(Stack *s, int n) {
    s->top++;
    s->elements[s->top] = n;
}

bool is_empty(Stack *s) {
    return s->top==0;
}

int pop(Stack *s) {
    if (!is_empty(s)) {
        s->top--;
        return s->elements[s->top + 1];
    } else {
        return -1;
    }
}


Stack *new_stack(int size) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->max_size = size;
    stack->elements = (int *) malloc(size * sizeof(int));
    stack->top = 0;
    return stack;
}

void delete_stack(Stack *s) {
    free(s->elements);
    free(s);
}

int main() {
    int size;
    scanf("%d", &size);
    Stack *s = new_stack(size);
    int tmp;
    for(int i=0;i<size;i++){
        scanf("%d", &tmp);
        push(s,tmp);
    }
    for(int i=0;i<size;i++){
        tmp=pop(s);
        printf("%d\n", tmp);
    }
    /***************************************
    * read values and push them on stack   *
    * pop values from stack and print them *
    ***************************************/


    delete_stack(s);
}