#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // 录入n
    double a[n];
    int t[n];

    int *sum = (int *)malloc((n + 1) * sizeof(int));
    if (sum == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        sum[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%lf%d", &a[i], &t[i]); // 存储每次操作的路灯
        sum[i] = (int)(a[i] * t[i]); // 存储每一次操作的最大值
    }
    int max = sum[0];
    for (int i = 1; i < n; i++) {
        if (sum[i] > sum[i - 1]) {
            max = sum[i];
        }
        /* 找到数组最大值并赋值 确定开关路灯范围 */
    }
    int *arrange = (int *)malloc((max + 1) * sizeof(int));
    if (arrange == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    for (int i = 0; i <= max; i++) {
        arrange[i] = 0;
    } /* 初始化状态为0 n次操作后如为偶数仍为关闭状态 */
    for (int i = 0; i < n; i++) {
        for (double j = a[i]; j < sum[i] + a[i]; j += a[i]) /* 每一次j变量变化路灯变化 */
        {   double b=j;
            int num = (int)b;
            arrange[num - 1]++;
        }
    }
    for (int i = 0; i <= max; i++) {
        if (arrange[i] % 2 == 1) {
            printf("%d\n", i + 1);
        }
    }
    free(sum);    // 释放分配的内存
    free(arrange);
    return 0;
}
