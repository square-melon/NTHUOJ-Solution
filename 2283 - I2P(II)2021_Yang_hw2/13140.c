#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    struct _Node *left, *right;
    int val;
} Node;

int numbers[200000], len, first = 0;

Node* construct(int, int);
void printPreOrder(Node*);

int main() {
    len = 0;
    while (scanf("%d", &numbers[len]) != EOF) len++;
    Node* root = construct(0, len-1);
    printPreOrder(root);
    printf("\n");
}

Node* construct(int s, int e) {
    if (s > e) return NULL;
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = numbers[e];
    node->right = NULL;
    node->left = NULL;
    if (s == e) return node;
    int l = s, r = e, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (numbers[mid] < numbers[e]) l = mid + 1;
        else r = mid;
    }
    node->left = construct(s, l-1);
    node->right = construct(l, e-1);
    return node;
}

void printPreOrder(Node *root) {
    if (first == 0) first = 1, printf("%d", root->val);
    else printf(" %d", root->val);
    if (root->left) printPreOrder(root->left);
    if (root->right) printPreOrder(root->right);
}