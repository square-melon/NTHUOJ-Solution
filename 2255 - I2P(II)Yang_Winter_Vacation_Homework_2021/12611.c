#include <stdio.h>

int isLeap(int);

int main() {
    int n;
    int y;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &y);
        int x = 0, leap = isLeap(y);
        do {
            if (isLeap(y)) x += 2;
            else x++;
            y++;
            x %= 7;
        } while (x || leap != isLeap(y));
        printf("%d\n", y);
    }
}

int isLeap(int y) {
    if (y % 400 == 0) return 1;
    else if (y % 100 == 0) return 0;
    else if (y % 4 == 0) return 1;
    else return 0;
}