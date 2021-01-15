#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE
{
	char color[10];
	struct _NODE *next;
} Node;

Node* addNode(char* color) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	strcpy(node->color, color);
	return node;
}

void insert(Node** node, char* color, int dest) {
	Node* head = *node;
	Node* newNode = addNode(color);
	while(head->next && dest--) head = head->next;
	newNode->next = head->next;
	head->next = newNode;
}

void erase1(Node** head, int dest) {
	Node* cur = *head;
	while (cur->next && --dest) cur = cur->next;
	if (cur->next) {
		Node* delNode = cur->next;
		cur->next = cur->next->next;
		free(delNode);
	}
}

void erase2(Node** head, char* color) {
	Node* cur = *head;
	while (cur->next) {
		if (strcmp(cur->next->color, color) == 0) {
			Node* delNode = cur->next;
			cur->next = cur->next->next;
			free(delNode);
		}else
			cur = cur->next;
	}
}

void reverse(Node** head, int dest1, int dest2) {
	if (dest1 == dest2) return;
	Node* cur = *head;
	if (dest1 > dest2) {
		int tmp = dest1;
		dest1 = dest2;
		dest2 = tmp;
	}
	int i = 0;
	while (cur->next && i+1 < dest1) {
		cur = cur->next;
		i++;
	}
	Node* left = cur->next;
	Node* right = cur->next;
	i++;
	while (right->next && i < dest2) {
		right = right->next;
		i++;
	}
	Node* prev = right->next;
	while (left != right) {
		Node* tmp = left;
		left = left->next;
		tmp->next = prev;
		prev = tmp;
	}
	cur->next = right;
	right->next = prev;
}

void show(Node **head);
