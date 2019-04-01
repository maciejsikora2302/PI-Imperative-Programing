#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    int *elements;
    int top;
    int max_size;
} Stack;

/***************************************
* paste here your Stack implementation *
***************************************/


void push(Stack *s, int n) {
    s->top++;
    s->elements[s->top] = n;
}

bool is_empty(Stack *s) {
    return s->top == 0;
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


typedef enum entry_type {
    number, add, subtract, multiply, divide
} entry_type;

entry_type parse(char *raw) {
    if (raw[0] == '+') return add;
    if (raw[0] == '-') return subtract;
    if (raw[0] == '*') return multiply;
    if (raw[0] == '/') return divide;
    return number;
}

/****************************
* implement functions below *
****************************/

void do_add(Stack *s) {
    int a, b;
    a = pop(s);
    b = pop(s);
    push(s, a + b);
}

void do_subtract(Stack *s) {
    int a, b;
    a = pop(s);
    b = pop(s);
    push(s, a - b);
}

void do_multiply(Stack *s) {
    int a, b;
    a = pop(s);
    b = pop(s);
    push(s, a * b);
}

void do_divide(Stack *s) {
    int a, b;
    a = pop(s);
    b = pop(s);
    push(s, a / b);
}

//tutaj trzeba poprawic rzutowanie, bo prawdopodobnie leci za daleko i dlatego wypisuje pierdoly
//trzeba tylko sprawdzic jak zprawdzic faktyczny rozmiar stringa w c
int zrzutuj(char *entry, int max_entry_size) {
    int suma = (int) entry[0] - 48;
    for (int i = 1; i < max_entry_size; i++) {
        suma *= 10;
        suma += (int) entry[i] - 48;
    }
    return suma;
}

int sizeOfString(char *tab, int max) {
    int rozmiar = 0;
    while (tab[rozmiar] != '\0' && rozmiar < max) rozmiar++;
    return rozmiar;
}

int read_and_calculate(int operands_count, int max_entry_size) {
    Stack *operands = new_stack(operands_count);
    char *entry = malloc((max_entry_size + 1) * sizeof(char));
    for (int zmienna = 0; zmienna < 2 * operands_count - 1; zmienna++) {
        for (int i = 0; i < max_entry_size; i++) entry[i] = '\0';
        scanf("%s", entry);
        switch (parse(entry)) {
            case add: {
                do_add(operands);
                break;
            }
            case subtract: {
                do_subtract(operands);
                break;
            }
            case multiply: {
                do_multiply(operands);
                break;
            }
            case divide: {
                do_divide(operands);
                break;
            }
            default: {
                push(operands, zrzutuj(entry, sizeOfString(entry, max_entry_size)));
                break;
            }

        }

        // put your code here
    }

    int result = pop(operands);
    delete_stack(operands);
    free(entry);
    return result;
}

int main() {
    int operands_count, max_entry_size;
    scanf("%d", &operands_count);
    scanf("%d", &max_entry_size);
    printf("%d\n", read_and_calculate(operands_count, max_entry_size));
}