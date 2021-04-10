#include <stdlib.h>
#include <string.h>
typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void printInfix(Node *root);

void freeTree(Node *root);

char s1[100] , s2[100];

int idx;

Node* addNode(char c) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void constructTree(Node** head) {
    if (idx < strlen(s2)) {
        char c = s2[idx++];
        if (c == '|' || c == '&') {
            *head = addNode(c);
            constructTree(&(*head)->right);
            constructTree(&(*head)->left);
        }else {
            *head = addNode(c);
        }
    }
}