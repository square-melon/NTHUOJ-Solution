#include <stdio.h>
#include <stdlib.h>
#define c 2e9

typedef struct NODE {
    struct NODE *right, *left;
    int val;
} Node;

Node* node[100000];
int l, r;

int prune(Node*);
void check(Node*);

int main() {
    int n;
    Node *root;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        node[i] = (Node*)malloc(sizeof(Node));
        node[i]->right = NULL, node[i]->left = NULL;
        scanf("%d", &node[i]->val);
    }
    for (int i = 0; i < n; i++) {
        int idx;
        scanf("%d", &idx);
        if (idx == 0) {
            root = node[i];
            continue;
        }
        idx--;
        char d;
        scanf("%c", &d);
        if (d == 'L') node[idx]->left = node[i];
        else node[idx]->right = node[i];
    }
    l = 0, r = c;
    check(root);
    for (int i = 0; i < n; i++) printf("%d%c", node[i]->val, i == n - 1 ? '\n' : ' ');
}

void check(Node *root) {
    if (root->val <= l || root->val >= r) {
        int lh = 0, rh = 0;
        if (root->left) lh = prune(root->left);
        if (root->right) rh = prune(root->right);
        int h = (lh > rh ? lh : rh) + 1;
        root->val = -h;
        return;
    }else {
        int preR = r;
        r = root->val;
        if (root->left) check(root->left);
        r = preR;
        int preL = l;
        l = root->val;
        if (root->right) check(root->right);
        l = preL;
        return;
    }
}

int prune(Node *root) {
    int lh = 0, rh = 0;
    if (root->left) lh = prune(root->left);
    if (root->right) rh = prune(root->right);
    int h = (lh > rh ? lh : rh) + 1;
    root->val = -h;
    return h;
}