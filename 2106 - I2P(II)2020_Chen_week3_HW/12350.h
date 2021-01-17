#include <stdio.h>
#include <stdlib.h>
#define next ptr_to_next_node
#define prev ptr_to_prev_node 

typedef struct _NODE
{
	char character;
	struct _NODE *ptr_to_next_node;
	struct _NODE *ptr_to_prev_node;
} Node;

Node *head, *tail;

void insert(Node** cursor, char s) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->character = s;
	newNode->prev = *cursor;
	newNode->next = (*cursor)->next;
	(*cursor)->next->prev = newNode;
	(*cursor)->next = newNode;
	if (*cursor == tail) tail = newNode;
}

void deletion(Node** cursor) {
	if ((*cursor) == tail) return;
	Node* byebye = (*cursor)->next;
	(*cursor)->next = (*cursor)->next->next;
	(*cursor)->next->prev = (*cursor);
	free(byebye);
}

void backspace(Node** cursor) {
	if ((*cursor) == head) return;
	Node* byebye = (*cursor);
	(*cursor) = (*cursor)->prev;
	(*cursor)->next = (*cursor)->next->next;
	(*cursor)->next->prev = (*cursor);
	free(byebye);
}

void go_left(Node** cursor, int x) {
	while (x--) *cursor = (*cursor)->prev;
}

void go_right(Node** cursor, int x) {
	while (x--) *cursor = (*cursor)->next;
}

void go_home(Node** cursor) {
	*cursor = head;
}

void go_end(Node** cursor) {
	*cursor = tail;
}

void show();
