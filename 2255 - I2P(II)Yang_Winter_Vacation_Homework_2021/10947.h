#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* addNode(int n) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(Node ** nd, int data) {
    if (data == 1) {
        if ((*nd)->next) *nd = (*nd)->next;
        else *nd = NULL;
        return;
    }
    Node* cur = *nd;
    data -= 2;
    while (cur->next && data--) cur = cur->next;
    if (!cur->next && data > 0) return;
    Node* byebye = cur->next;
    cur->next = cur->next->next;
    free(byebye);
}

Node* createList() {
    int n;
    Node* head = (Node*)malloc(sizeof(Node));
    Node* cur = head;
    while (scanf("%d", &n), n != -1) cur = cur->next = addNode(n);
    return head->next;
}
