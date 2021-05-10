#include <stdio.h>

int nodeIndex[200005], lch[200005], rch[200005], inorder[200005], parent[200005], sol[200005];
int n, root, idx;

void traversal(int);

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &lch[i], &rch[i]);
            if (lch[i] == 0) {
                lch[i] = rch[i];
                rch[i] = 0;
            }
            parent[lch[i]] = i;
            parent[rch[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &inorder[i]);
            nodeIndex[inorder[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (parent[i] == 0) {
                root = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (rch[i] == 0) {
                if (nodeIndex[lch[i]] > nodeIndex[i]) {
                    rch[i] = lch[i];
                    lch[i] = 0;
                }
            } else {
                if (nodeIndex[lch[i]] > nodeIndex[rch[i]]) {
                    int tmp = lch[i];
                    lch[i] = rch[i];
                    rch[i] = tmp;
                }
            }
        }
        idx = 1;
        traversal(root);
        int check = 1;
        for (int i = 1; i <= n; i++) {
            if (sol[i] != inorder[i]) {
                check = 0;
                break;
            }
        }
        if (check) printf("YES\n");
        else printf("NO\n");
        for (int i = 1; i <= n; i++) parent[i] = 0;
    }
}

void traversal(int n) {
    if (lch[n] != 0) traversal(lch[n]);
    sol[idx++] = n;
    if (rch[n] != 0) traversal(rch[n]);
}