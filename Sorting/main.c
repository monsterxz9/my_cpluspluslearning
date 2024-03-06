#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        _Bool flag = 1;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;
            }
        }
        if (flag)break;
    }
}

int binarySearch(int arr[], int left, int right, int target) {
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target == arr[mid])return mid + 1;
        else if (target < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

void insertSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int tmp = arr[i];
        int j = binarySearch(arr, 0, i - 1, tmp);
        for (int k = i; k > j; k--) {
            arr[k] = arr[k - 1];
        }
        arr[j] = tmp;
    }
}

void selectSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i; j < size; ++j) {
            if (arr[j] < arr[min])min = j;
        }
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}

int main() {
    int arr[10] = {3, 5, 7, 2, 9, 0, 6, 1, 8, 4};
    bubbleSort(arr, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
