#include <stdio.h>

char dir[200005];
int Lpre, Rpre;

int main() {
    int n;
    int res = -2;
    scanf("%d", &n);
    scanf("%s", dir);
    for (int i = 0; i < n; i++) {
        if (dir[i] == 'L') {
            scanf("%d", &Lpre);
            if (i != 0 && dir[i-1] == 'R') {
                if (res == -2 || res > Lpre - Rpre) res = Lpre - Rpre;
            }
        }else {
            scanf("%d", &Rpre);
        }
    }
    printf("%d\n", res / 2);
}