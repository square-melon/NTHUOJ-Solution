#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* next;
	int val;
} Node;

void createLinkedList(Node **head, int N, int *arr) {
	*head = (Node*)malloc(sizeof(Node));
	(*head)->val = arr[1];
	Node *cur = *head;
	for (int i = 2; i <= N; i++) {
		cur->next = (Node*)malloc(sizeof(Node));
		cur = cur->next;
		cur->val = arr[i];
	}
	cur->next = *head;
}

void swapTwoSegment(Node **head, int a, int b, int len) {
	Node *cura = *head, *curb = *head;
	a--, b--;
	while (a--) cura = cura->next;
	while (b--) curb = curb->next;
	while (len--) {
		int temp = cura->val;
		cura->val = curb->val;
		curb->val = temp;
		cura = cura->next;
		curb = curb->next;
	}
}
