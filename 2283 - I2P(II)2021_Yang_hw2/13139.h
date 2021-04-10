#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node *left, *right;
	int id;
} Node;

int isRoot[1000000];

Node* buildBinaryTree(int n, int *lch, int *rch) {
	Node **node = (Node**)malloc(sizeof(Node*) * n);
	for (int i = 0; i < n; i++) node[i] = (Node*)malloc(sizeof(Node));
	for (int i = 0; i < n; i++) {
		node[i]->id = i;
		node[i]->left = lch[i] == -1 ? NULL : node[lch[i]];
		node[i]->right = rch[i] == -1 ? NULL : node[rch[i]];
	}
	Node* root = node[0];
	free(node);
	return root;
}

void Traversal(Node *root, int *sz) {
	sz[root->id] = 1;
	if (root->left) {
		Traversal(root->left, sz);
		sz[root->id] += sz[root->left->id];
	}
	if (root->right) {
		Traversal(root->right, sz);
		sz[root->id] += sz[root->right->id];
	}
}

void freeBinaryTree(Node *root) {
	if (root->left) freeBinaryTree(root->left);
	if (root->right) freeBinaryTree(root->right);
	free(root);
}
