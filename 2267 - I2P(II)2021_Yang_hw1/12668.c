#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    char c;
    struct NODE* next;
    struct NODE* prev;
} Node;

int main() {
    int t, n;
    char c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        Node* head = (Node*)malloc(sizeof(Node));
        Node* tail = (Node*)malloc(sizeof(Node));
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
        Node* cur = head;
        c = getchar();
        for (int i = 0; i < n; i++) {
            c = getchar();
            if (c == 'L') cur = cur->prev;
            else if (c == 'R') cur = cur->next;
            else if (c == 'B') {
                cur = cur->prev;
                Node* tofree = cur->next;
                cur->next = cur->next->next;
                cur->next->prev = cur;
                free(tofree);
            }else {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->c = c;
                newNode->next = cur->next;
                newNode->prev = cur;
                cur->next->prev = newNode;
                cur->next = newNode;
                cur = cur->next;
            }
        }
        c = getchar();
        cur = head;
        while (cur->next != tail) {
            printf("%c", cur->next->c);
            cur = cur->next;
        }
        printf("\n");
        while (head) {
            Node* tofree = head;
            head = head->next;
            free(tofree);
        }
    }
}