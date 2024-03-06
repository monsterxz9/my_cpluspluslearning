#include <stdio.h>

// 递归计算阶乘
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // 输出阶乘结果
    printf("%d\n", factorial(n));

    return 0;
}
