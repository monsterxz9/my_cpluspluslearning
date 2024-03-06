#include <stdio.h>
#include <stdlib.h>

// 比较函数用于 qsort 函数的排序
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, m;

    // 读取输入
    scanf("%d %d", &n, &m);

    int *votes = (int *)malloc(m * sizeof(int));

    // 读取选票编号
    for (int i = 0; i < m; i++) {
        scanf("%d", &votes[i]);
    }

    // 使用标准库函数 qsort 进行排序
    qsort(votes, m, sizeof(int), compare);

    // 输出排序后的选票编号
    for (int i = 0; i < m; i++) {
        printf("%d ", votes[i]);
    }

    // 释放动态分配的内存
    free(votes);

    return 0;
}
