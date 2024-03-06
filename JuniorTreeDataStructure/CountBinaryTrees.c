#include <stdio.h>
//dynamic programming
/*
int main() {
    int n;
    scanf("%d", &n);
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[i - j - 1] * dp[j];
        }
    }
    printf("%d", dp[n]);
    return 0;
}
*/
//formula
int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", factorial(2 * n) /
                 (factorial(n) * factorial(n + 1))
    );
    return 0;
}