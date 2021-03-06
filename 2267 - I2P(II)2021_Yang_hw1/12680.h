#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;

Node* ReadOneList() {
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    int n;
    char buf;
    scanf("%d %c", &n, &buf);
    newNode->data = (int*)malloc(sizeof(int)*n);
    newNode->size = n;
    for (int i = 0; i < n; i++) scanf("%d", &newNode->data[i]);
    newNode->next = NULL;
    return newNode;
}

void PrintList(Node* head) {
    Node* cur = head;
    while (cur->next) {
        for (int i = 0; i < cur->next->size; i++) printf("%d%s", cur->next->data[i], i != cur->next->size-1 ? " " : "");
        printf("\n");
        cur = cur->next; 
    }
}

void Merge(Node* head, int x, int y) {
    int i = 1;
    Node *cur = head, *curr = head;
    while (i != x) {
        cur = cur->next;
        i++;
    }
    i = 0;
    while (i != y) {
        curr = curr->next;
        i++;
    }
    int newSize = curr->size + cur->next->size;
    int* bufdata = (int*)malloc(sizeof(int)*curr->size);
    for (int i = 0; i < curr->size; i++) bufdata[i] = curr->data[i];
    free(curr->data);
    curr->data = (int*)malloc(sizeof(int)*newSize);
    for (int i = 0; i < curr->size; i++) curr->data[i] = bufdata[i];
    for (int i = curr->size; i < newSize; i++) curr->data[i] = cur->next->data[i-curr->size];
    free(cur->next->data);
    Node* tofree = cur->next;
    cur->next = cur->next->next;
    free(tofree);
    curr->size = newSize;
}

void Cut(Node* head, int x, int y) {
    Node* cur = head;
    while (x--) cur = cur->next;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = cur->next;
    cur->next = newNode;
    newNode->data = (int*)malloc(sizeof(int)*(cur->size-y));
    newNode->size = cur->size-y;
    for (int i = 0; i < cur->size-y; i++) newNode->data[i] = cur->data[i+y];
    int* bufdata = (int*)malloc(sizeof(int)*y);
    for (int i = 0; i < y; i++) bufdata[i] = cur->data[i];
    free(cur->data);
    cur->data = (int*)malloc(sizeof(int)*y);
    for (int i = 0; i < y; i++) cur->data[i] = bufdata[i];
    cur->size = y;
}

#endif