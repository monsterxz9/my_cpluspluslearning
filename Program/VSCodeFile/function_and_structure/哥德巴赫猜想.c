#include <stdio.h>

// 函数用于判断一个数是否是质数
int isPrime(int num) {
    if (num <= 1) {
        return 0;  // 不是质数
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // 不是质数
        }
    }
    return 1;  // 是质数
}

int main() {
    int N;
    scanf("%d", &N);

    if (N >= 4) {
        for (int i = 4; i <= N; i += 2) {
            for (int j = 2; j <= i / 2; j++) {
                if (isPrime(j) && isPrime(i - j)) {
                    printf("%d=%d+%d\n", i, j, i - j);
                    break;
                }
            }
        }
    }

    return 0;
}
