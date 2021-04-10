#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTNode {
    struct BTNode *right;
    struct BTNode *left;
    char data;
} Node;

char str[35];
int pos = 0, val[4];
Node *root;

Node* constructTree();
Node* makeNode(char);
void sol(int);
int implement(Node*);


int main() {
    scanf("%s", str);
    root = constructTree();
    sol(0);
}

Node* constructTree() {
    Node *node = NULL;
    char c = str[pos++];
    if (c == '|' || c == '&') {
        node = makeNode(c);
        node->left = constructTree();
        node->right = constructTree();
    }else node = makeNode(c);
    return node;
}

Node* makeNode(char c) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = c;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void sol(int n) {
    if (n == 4) {
        for (int i = 0; i < 4; i++) printf("%d ", val[i]);
        printf("%d\n", implement(root));
    }else {
        val[n] = 0;
        sol(n+1);
        val[n] = 1;
        sol(n+1);
    }
}

int implement(Node *root) {
    if (root->left && root->right) {
        if (root->data == '|') return implement(root->left) | implement(root->right);
        else return implement(root->left) & implement(root->right);
    }else return val[root->data - 'A'];
}