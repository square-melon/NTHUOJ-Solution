#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int val;
    struct NODE* next;
} Node;

void insert(int, int);
void erase(int);
void move(int);
void show();

Node* head;
int size = 1;

int main() {
    int x;
    scanf("%d", &x);
    head = (Node*)malloc(sizeof(Node));
    head->val = x;
    head->next = NULL;
    int t;
    scanf("%d", &t);
    while (t--) {
        char option[7];
        scanf("%s", option);
        if (option[0] == 'i') {
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            insert(v1, v2);
        }else if (option[0] == 'e') {
            int v1;
            scanf("%d", &v1);
            erase(v1);
        }else if (option[0] == 'm') {
            int v1;
            scanf("%d", &v1);
            move(v1);
        }else show();
    }
}

void insert(int v1, int v2) {
    Node *cur = head, *then = cur->next;
    for (int i = 0; i < v2; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = v1;
        newNode->next = NULL;
        cur->next = newNode;
        cur = cur->next;
    }
    cur->next = then;
    size += v2;
}

void erase(int v1) {
    size -= v1;
    while (v1--) {
        Node* bye = head->next;
        head->next = head->next->next;
        free(bye);
    }
}

void move(int v1) {
    Node *cur = head, *newHead, *newEnd;
    while (v1 < 0) v1 += size;
    v1 %= size;
    if (v1 == 0) return;
    while (cur->next) {
        if (v1 == 1) {
            newEnd = cur;
            newHead = cur->next;
        }
        cur = cur->next;
        v1--;
    }
    cur->next = head;
    newEnd->next = NULL;
    head = newHead;
}

void show() {
    Node *cur = head;
    while (cur->next) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("%d\n", cur->val);
}