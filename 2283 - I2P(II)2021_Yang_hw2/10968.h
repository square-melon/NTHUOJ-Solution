#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void constructTree(Node** head);

void printInfix(Node *root) {
    if (root->left) printInfix(root->left);
    printf("%c", root->data);
    if (root->right) {
        int bracket = root->right->data == '|' || root->right->data == '&';
        if (bracket)
            printf("(");
        printInfix(root->right);
        if (bracket)
            printf(")");
    }
}

void freeTree(Node *root);

#endif