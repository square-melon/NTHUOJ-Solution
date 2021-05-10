void square1(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] *= arr[i];
}

void square2(int *arr, int n) {
    int *p = arr;
    for (int i = 0; i < n; i++)
        *(p + i) *= *(p + i);
}