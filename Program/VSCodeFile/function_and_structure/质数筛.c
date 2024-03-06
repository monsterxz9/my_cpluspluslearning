#include <stdio.h>
#include <stdbool.h>

// 最大范围
#define MAX 100001

// 判断是否是质数
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }

    printf("Primes: ");
    for (int i = 0; i < n; ++i) {
        if (isPrime(numbers[i])) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    return 0;
}
