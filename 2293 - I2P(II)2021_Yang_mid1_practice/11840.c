#include <stdio.h>
#include <stdlib.h>

typedef struct TABLE {
    int size;
    int books[25];
} Table;

Table table[25];
int where[25], n;

void returnBook(int);
void printBook();

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        table[i].size = 1;
        table[i].books[0] = i;
        where[i] = i;
    }
    char ch[5];
    while (1) {
        scanf("%s", ch);
        if (ch[0] == 'e') break;
        else if (ch[0] == 'm') {
            int a, b;
            scanf("%d %s %d", &a, ch, &b);
            if (where[a] == where[b] || a == b) continue;
            if (ch[1] == 'n') {
                returnBook(a);
                returnBook(b);
                table[where[b]].books[table[where[b]].size] = a;
                table[where[b]].size++;
                table[where[a]].size--;
                where[a] = where[b];
            }else {
                returnBook(a);
                table[where[b]].books[table[where[b]].size] = a;
                table[where[b]].size++;
                table[where[a]].size--;
                where[a] = where[b];
            }
        }else {
            int a, b;
            scanf("%d %s %d", &a, ch, &b);
            if (where[a] == where[b] || a == b) continue;
            if (ch[1] == 'n') {
                returnBook(b);
                int i;
                for (i = 0; i < table[where[a]].size; i++) if (table[where[a]].books[i] == a) break;
                int x = i, buf = where[a];
                for (; i < table[buf].size; i++) {
                    table[where[b]].books[table[where[b]].size] = table[buf].books[i];
                    where[table[buf].books[i]] = where[b];
                    table[where[b]].size++;
                }
                table[buf].size = x;
            }else {
                int i;
                for (i = 0; i < table[where[a]].size; i++) if (table[where[a]].books[i] == a) break;
                int x = i, buf = where[a];
                for (; i < table[buf].size; i++) {
                    table[where[b]].books[table[where[b]].size] = table[buf].books[i];
                    where[table[buf].books[i]] = where[b];
                    table[where[b]].size++;
                }
                table[buf].size = x;
            }
        }
    }
    printBook();
}

void printBook() {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < table[i].size; j++) printf(" %d", table[i].books[j]);
        printf("\n");
    }
}

void returnBook(int n) {
    for (int i = table[where[n]].size - 1; i >= 0; i--) {
        if (table[where[n]].books[i] == n) return;
        table[where[n]].size--;
        int x = table[where[n]].books[i];
        table[x].books[0] = x;
        table[x].size++;
        where[x] = x;
    }
}