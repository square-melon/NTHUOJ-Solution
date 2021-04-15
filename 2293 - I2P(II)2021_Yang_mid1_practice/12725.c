#include <stdio.h>
#include <stdlib.h>
#define min(a, b) a < b ? a : b

typedef struct NODE {
    struct NODE *right, *left;
    char op;
    int val;
} Node;

char expr[300005];
int idx;

Node* addNode(char);
Node* construct();
Node* copy(Node*);
Node* leftSpin(Node*);
Node* rightSpin(Node*);
void reCal(Node*);

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", expr);
    idx = 0;
    Node *root = construct();
    Node *cur_l = copy(root);
    int sol = root->val;
    while (cur_l->right->op == '+' || cur_l->right->op == '-' || cur_l->right->op == '*') {
        cur_l = leftSpin(cur_l);
        reCal(cur_l->left);
        reCal(cur_l);
        sol = min(sol, cur_l->val);
    }
    Node *cur_r = copy(root);
    while (cur_r->left->op == '+' || cur_r->left->op == '-' || cur_r->left->op == '*') {
        cur_r = rightSpin(cur_r);
        reCal(cur_r->right);
        reCal(cur_r);
        sol = min(sol, cur_r->val);
    }
    printf("%d\n", sol);
}

Node* addNode(char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (c >= '0' && c <= '9') {
        newNode->val = c - '0';
        newNode->op = c;
    }else {
        newNode->op = c;
        newNode->val = 0;
    }
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* construct() {
    Node *root;
    char c = expr[idx++];
    root = addNode(c);
    if (c == '+' || c == '-' || c == '*') {
        root->left = construct();
        root->right = construct();
        if (c == '+') root->val = root->left->val + root->right->val;
        else if (c == '-') root->val = root->left->val - root->right->val;
        else if (c == '*') root->val = root->left->val * root->right->val;
    }
    return root;
}

Node* copy(Node *root) {
    Node *cpyroot = (Node*)malloc(sizeof(Node));
    cpyroot->val = root->val;
    cpyroot->op = root->op;
    cpyroot->left = NULL, cpyroot->right = NULL;
    if (root->left) cpyroot->left = copy(root->left);
    if (root->right) cpyroot->right = copy(root->right);
    return cpyroot;
}

Node* leftSpin(Node *root) {
    Node *newRoot = root->right, *newRootLeftRight = root->right->left;
    newRoot->left = root;
    root->right = newRootLeftRight;
    return newRoot;
}

Node* rightSpin(Node *root) {
    Node *newRoot = root->left, *newRootRightLeft = root->left->right;
    newRoot->right = root;
    root->left = newRootRightLeft;
    return newRoot;
}

void reCal(Node *root) {
    if (root->op == '+') root->val = root->left->val + root->right->val;
    else if (root->op == '-') root->val = root->left->val - root->right->val;
    else if (root->op == '*') root->val = root->left->val * root->right->val;
}