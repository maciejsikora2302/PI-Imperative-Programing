#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char MAX_NAME_SIZE = 30;

typedef struct node {
    struct node *left, *right, *parent;
    int number;
    char *name;
} node;

node *create_node(int number, char *name) {
    /*********************
    * put your code here *
    * *******************/
    node *tmp = malloc(sizeof(node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = NULL;
    tmp->number = number;
    tmp->name = malloc(MAX_NAME_SIZE * sizeof(char *));
    strcpy(tmp->name, name);
    return tmp;
}

void delete_tree(node *root) {
    /*********************
    * put your code here *
    * *******************/
    if (root == NULL) return;
    node *tmp1 = root->left;
    node *tmp2 = root->right;
    free(root->name);
    free(root);
    delete_tree(tmp1);
    delete_tree(tmp2);
}

node *insert(node *root, node *to_insert) {
    /*********************
    * put your code here *
    * *******************/
    if (to_insert == NULL)return root;
    if (root == NULL) {
        root = to_insert;
    } else {
        node *tmp_root = root;
        while (true) {
            if (tmp_root->number <= to_insert->number) {
                if (tmp_root->right == NULL) {
                    to_insert->parent = tmp_root;
                    tmp_root->right = to_insert;
                    break;
                } else {
                    tmp_root = tmp_root->right;
                }
            } else {
                if (tmp_root->left == NULL) {
                    to_insert->parent = tmp_root;
                    tmp_root->left = to_insert;
                    break;
                } else {
                    tmp_root = tmp_root->left;
                }
            }
        }
    }
    return root;
}

node *find(node *root, int number) {
    /*********************
    * put your code here *
    * *******************/
    while (root != NULL) {
        if (root->number == number)break;
        if (root->number < number) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return root;
}

node *delete(node *root, int number) {
    /*********************
    * put your code here *
    * *******************/
    node *to_delete = find(root, number);
    if (to_delete != NULL) {
        if (to_delete->parent == NULL) {
            if (to_delete->left != NULL) {
                to_delete->left->parent = NULL;
                root = insert(to_delete->left, to_delete->right);
            } else {
                root = to_delete->right;
                root->parent = NULL;
            }
            free(to_delete->name);
            free(to_delete);
            return root;
        } else {
            if (to_delete == to_delete->parent->left) {
                to_delete->parent->left = NULL;
            } else if (to_delete == to_delete->parent->right) {
                to_delete->parent->right = NULL;
            }
            root = insert(root, to_delete->left);
            root = insert(root, to_delete->right);
            free(to_delete->name);
            free(to_delete);
        }
    }
    return root;
}

void wypisz_in_order(node *root) {
    if (root != NULL) {
        wypisz_in_order(root->left);
        printf("%s ", root->name);
        wypisz_in_order(root->right);
    }
}

int main() {
    int n, r, f;
    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &f);

    node *root = NULL;
    int number;
    char *name = malloc(MAX_NAME_SIZE * sizeof(char));

    while (n-- > 0) {
        scanf("%d", &number);
        scanf("%s", name);
        root = insert(root, create_node(number, name));
    }
    //wypisz_in_order(root);
    while (r-- > 0) {
        scanf("%d", &number);
        root = delete(root, number);
    }

    while (f-- > 0) {
        scanf("%d", &number);
        node *x = find(root, number);
        printf("%s\n", x == NULL ? "NOTFOUND" : x->name);
    }

    delete_tree(root);
    free(name);
}



/*node *origin_root = root;
if (root->number == number) {
    if (root->parent == NULL) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        node *tmp = root;
        if (root->right != NULL) {
            tmp = tmp->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
        } else {
            tmp = root->left;
        }
        if (tmp == NULL) return tmp;
        tmp->left = root->left;
        tmp->right = root->right;
        tmp->parent = NULL;
        free(root);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        node *tmp = root;
        if (root->right != NULL) {
            tmp = tmp->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
        } else {
            tmp = root->left;
        }
        if (tmp == NULL) return tmp;
        tmp->left = root->left;
        tmp->right = root->right;
        tmp->parent = NULL;
        free(root);
    }
}*/