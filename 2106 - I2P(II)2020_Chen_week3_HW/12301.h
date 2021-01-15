#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;

Node *createList(int n) {
    Node* head;
    head = (Node*)malloc(sizeof(Node));
    head->number = 1;
    head->next = NULL;
    Node* cur = head;
    for (int i = 2; i <= n; i++) {
        cur->next = (Node*)malloc(sizeof(Node));
        cur = cur->next;
        cur->number = i;
        cur->next = NULL;
    }
    cur->next = head;
    return head;
}
void freeList(Node* head) {
    free(head);
}

int solveJosephus(Node **head, int step) {
    Node* cur = (*head);
    int size = 1;
    while (cur->next != (*head)) {
        cur = cur->next;
        size++;
    }
    for (int i = size; i > 1; i--) {
        int j = step % i == 0 ? i : step % i;
        for (; j > 1; j--) cur = cur->next;
        Node* byebye = cur->next;
        cur->next = cur->next->next;
        free(byebye);
    }
    (*head) = cur;
    return cur->number;
}

#endif
