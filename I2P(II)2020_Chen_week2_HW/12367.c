// Using Prefix Sum
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    long long int* num;
    long long int* prefixSum;
    while (scanf("%d %d", &n, &q) != EOF) {
        num = (long long int*)malloc(sizeof(long long int)*(n+1));
        prefixSum = (long long int*)malloc(sizeof(long long int)*(n+1));
        prefixSum[0] = 0;
        for (int i = 1; i < n+1; i++) {
            scanf("%lld", &num[i]);
            prefixSum[i] = prefixSum[i-1]+num[i];
        }
        long long int maxSum = 0;
        int rs, re;
        while (q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            long long int tmp;
            if (b >= a) tmp = prefixSum[b] - prefixSum[a-1];
            else tmp = prefixSum[n] - (prefixSum[a-1] - prefixSum[b]);
            if (tmp > maxSum) maxSum = tmp, rs = a, re = b;
        }
        printf("Max_range: (%d,%d); Value: %lld\n", rs, re, maxSum);
        free(num);
        free(prefixSum);
    }
}