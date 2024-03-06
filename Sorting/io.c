//
// Created by Mark Tween on 2023/12/30.
//
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int left, int right, int array[], int m) {
    if (left > right) return -1;
    int mid;
    mid = (left + right) / 2;
    if (array[mid] == m) return mid;
    else if (array[mid] > m) return binarySearch(0, mid - 1, array, m);
    else if (array[mid] < m) return binarySearch(mid + 1, right, array, m);

}

int main() {
    int n, m;
    scanf_s("%d %d", &n, &m);
    int *arr;
    arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }
    int *mptr;
    mptr = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf_s("%d", &mptr[i]);
    }
    for (int i = 0; i < m; i++) {
        printf("%d ", binarySearch(0, n - 1, arr, mptr[i]) + 1);
    }
    free(arr);  // Free allocated memory
    free(mptr); // Free allocated memory
    return 0;
}
