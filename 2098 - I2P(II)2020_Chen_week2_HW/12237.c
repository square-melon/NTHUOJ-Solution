#include <stdio.h>

int main() {
    float f;
    while (scanf("%f", &f) != EOF) {
        int IEEE[32] = {0};
        int* p = (int*)&f;
        for (int i = 0; i < 32; i++) 
            if ((*p >> i) & 1) IEEE[i] = 1;
        for (int i = 31; i >= 0; i--)
            printf("%d", IEEE[i] == 1? 1 : 0);
        printf("\n");
    }
}