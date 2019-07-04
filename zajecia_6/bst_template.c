#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left, *right, *parent;
    int value;
} node;


node *create_node(int val) {
    /*********************
    * put your code here *
    * *******************/
    node *tmp = malloc(sizeof(node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = NULL;
    tmp->value = val;
    return tmp;
}

void delete_tree(node *root) {
    /*********************
    * put your code here *
    * *******************/
    if(root==NULL) return;
    node* tmp1=root->left;
    node* tmp2=root->right;
    free(root);
    delete_tree(tmp1);
    delete_tree(tmp2);
}

void insert(node *root, node *to_insert) {
    /*********************
    * put your code here *
    * *******************/

    if (root == NULL) {
        root = to_insert;
        return;
    }
    while (true) {
        if (root->value <= to_insert->value) {
            if (root->right == NULL) {
                to_insert->parent = root;
                root->right = to_insert;
                return;
            }
            root = root->right;
        } else {
            if (root->left == NULL) {
                to_insert->parent = root;
                root->left = to_insert;
                return;
            }
            root = root->left;
        }
    }
}

void print_in_order(node *root) {
    /*********************
    * put your code here *
    * *******************/
    if(root!=NULL){
        print_in_order(root->left);
        printf("%d\n",root->value);
        print_in_order(root->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    node *root = NULL;
    int val;

    if (n-- > 0) {
        scanf("%d", &val);
        root = create_node(val);
    }
    while (n-- > 0) {
        scanf("%d", &val);
        insert(root, create_node(val));
    }

    print_in_order(root);

    delete_tree(root);
}
