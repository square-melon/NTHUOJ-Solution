#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTNode {
    struct BTNode *left;
    struct BTNode *right;
    char data;
} Node;

Node *root;
char str[260];
int pos;

Node* FACTOR();
Node* EXPR();
Node* makeNode(char);
void printInfix(Node*);
void freeTree(Node*);

int main() {
    scanf("%s", str);
    pos = strlen(str)-1;
    Node *root = EXPR();
    printInfix(root);
    freeTree(root);
}

Node* EXPR() {
    Node *right = NULL, *node = NULL;
    if (pos >= 0) {
        right = FACTOR();
        if (pos > 0) {
            char c = str[pos];
            if (c == '&' || c == '|') {
                node = makeNode(c);
                node->right = right;
                pos--;
                node->left = EXPR();
            }else node = right;
        }else node = right;
    }
    return node;
}

Node* FACTOR() {
    Node *node = NULL;
    char c = str[pos--];
    if (c >= 'A' && c <= 'D') node = makeNode(c);
    else if (c == ')') {
        node = EXPR();
        pos--;
    }
    return node;
}

Node* makeNode(char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = c;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void printInfix(Node *root) {
    if (root->left) printInfix(root->left);
    printf("%c", root->data);
    if (root->right) {
        int bracket = root->right->data == '|' || root->right->data == '&';
        if (bracket) printf("(");
        printInfix(root->right);
        if (bracket) printf(")");
    }
}

void freeTree(Node* root) {
    if (root->left) freeTree(root->left);
    if (root->right) freeTree(root->right);
    free(root);
}