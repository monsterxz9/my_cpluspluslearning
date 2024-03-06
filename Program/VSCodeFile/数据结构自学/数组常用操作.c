#include <stdio.h>
#include <stdlib.h> // 用于qsort函数
#include <string.h> // 用于memcpy和memcmp函数

int main() {
    // 创建数组并初始化
    int arr1[5] = {3, 1, 4, 1, 5};
    int arr2[5];

    // 访问和修改数组元素
    printf("Element at index 2: %d\n", arr1[2]); // 访问
    arr1[2] = 10; // 修改

    // 获取数组长度
    int length = sizeof(arr1) / sizeof(arr1[0]);
    printf("Array length: %d\n", length);

    // 遍历数组
    printf("Array elements: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // 排序数组（升序）
    qsort(arr1, length, sizeof(int), cmp); // 使用快速排序
    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // 查找数组元素
    int target = 4;
    int found = linearSearch(arr1, length, target);
    if (found != -1) {
        printf("%d found at index %d\n", target, found);
    } else {
        printf("%d not found in the array\n", target);
    }

    // 拷贝数组
    int copiedArray[length];
    memcpy(copiedArray, arr1, sizeof(arr1));

    // 比较数组
    int isEqual = memcmp(arr1, copiedArray, sizeof(arr1));
    if (isEqual == 0) {
        printf("arr1 and copiedArray are equal\n");
    } else {
        printf("arr1 and copiedArray are not equal\n");
    }

    return 0;
}

// 用于qsort函数的比较函数
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// 线性搜索函数
int linearSearch(int arr[], int length, int target) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == target) {
            return i; // 找到目标值返回索引
        }
    }
    return -1; // 未找到目标值返回-1
}
