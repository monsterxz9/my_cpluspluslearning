#include <stdio.h>
#include <stdlib.h>

// 比较函数用于 qsort 函数的排序
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;

    // 读取输入
    scanf("%d", &N);

    int *numbers = (int *)malloc(N * sizeof(int));

    // 读取待排序的数
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    // 使用标准库函数 qsort 进行排序
    qsort(numbers, N, sizeof(int), compare);

    // 输出排序后的数
    for (int i = 0; i < N; i++) {
        printf("%d", numbers[i]);

        // 在除了最后一个数之外的数后面输出空格
        if (i < N - 1) {
            printf(" ");
        }
    }

    // 释放动态分配的内存
    free(numbers);

    return 0;
}
