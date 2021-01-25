#include <stdio.h>
#include <stdlib.h>
#define r ptr_to_right_node
#define l ptr_to_left_node

typedef struct _NODE
{
	int number;
	struct _NODE *ptr_to_right_node;
	struct _NODE *ptr_to_left_node;
} Node;

int cnt = 0;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end) {
	if (inorder_start > inorder_end) return NULL;
	Node* head = (Node*)malloc(sizeof(Node));
	head->r = NULL;
	head->l = NULL;
	head->number = preorder[cnt];
	if (inorder_start == inorder_end) {
		cnt++;
		return head;
	}
	int num;
	for (int i = inorder_start; i <= inorder_end; i++) {
		if (preorder[cnt] == inorder[i]) {
			num = i;
			break;
		}
	}
	cnt++;
	head->l = buildTree(inorder, preorder, inorder_start, num - 1);
	head->r = buildTree(inorder, preorder, num + 1, inorder_end);
	return head;
}

void showPostorder(Node* root) {
	if (root->l) showPostorder(root->l);
	if (root->r) showPostorder(root->r);
	printf("%d ", root->number);
}

void freeTree(Node *root) {
	if (root->l) freeTree(root->l);
	if (root->r) freeTree(root->r);
	free(root);
	cnt = 0;
}

