#include <stdlib.h>
#define left left_child
#define right right_child

typedef struct _NODE {
	int level;
	struct _NODE *left_child, *right_child;
} Node;

Node* insert(int n) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->level = n;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

Node* deleteNode(Node* root) {
	Node* cur;
	if (!root->right && !root->left) {
		free(root);
		return NULL;
	}else if (root->left) {
		Node *prev = NULL;
		cur = root->left;
		while (cur->right) {
			prev = cur;
			cur = cur->right;
		}
		if (prev) {
			prev->right = cur->left;
			cur->left = root->left;
		}
		cur->right = root->right;
	}else {
		Node *prev = NULL;
		cur = root->right;
		while (cur->left) {
			prev = cur;
			cur = cur->left;
		}
		if (prev) {
			prev->left = cur->right;
			cur->right = root->right;
		}
		cur->left = root->left;
	}
	free(root);
	return cur;
}

void build_tree(Node **now, int *arr, int l, int r) {
	int mid = (l + r) / 2;
	(*now) = insert(arr[mid]);
	if (mid - 1 >= l) build_tree(&(*now)->left, arr, l, mid - 1);
	if (mid + 1 <= r) build_tree(&(*now)->right, arr, mid + 1, r);
}

int query_heatstroke(Node *now, int x) {
	while(now && now->level != x){
		if(now->level > x) now = now->left;
		else if(now->level < x) now = now->right;
	}
	if(now && now->level == x) return 1;
	return 0;
}

void eat_rat(Node **root, int x) {
	Node* cur = *root;
	Node* prev = NULL;
	while (x != cur->level) {
		prev = cur;
		if (x < cur->level) cur = cur->left;
		else cur = cur->right;
	}
	if (!prev) *root = deleteNode(*root);
	else if (prev->left == cur) prev->left = deleteNode(cur);
	else prev->right = deleteNode(cur);
}
