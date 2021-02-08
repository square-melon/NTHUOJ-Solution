#include <stdio.h>

char name[200005];
char alphabet[27];

int main() {
    int m, n;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        alphabet[i] = c;
    }
    scanf("%d %d", &n, &m);
    scanf("%s", name);
    while (m--) {
        char former, latter;
        scanf("%c", &former);
        scanf("%c %c", &former, &latter);
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] == former) alphabet[i] = latter;
            else if (alphabet[i] == latter) alphabet[i] = former;
        }
    }
    for (int i = 0; i < n; i++) printf("%c", alphabet[name[i] - 'a']);
    printf("\n");
}