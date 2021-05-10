void f1(int **arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        int *p = arr[i];
        for (int j = 0; j < n; j++)
            *(p + j) = i * 10 + j;
    }
}

void f2(int arr[][n], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            arr[i][j] = i * 10 + j;
    }
}