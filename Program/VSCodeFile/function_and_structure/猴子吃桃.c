#include <stdio.h>

int calculate_peach_count(int n) {
    int peach_count = 1;  // 初始桃子数量
    for (int day = n - 1; day > 0; day--) {
        peach_count = (peach_count + 1) * 2;
    }
    return peach_count;
}

int main() {
    int n;
    scanf("%d", &n);
    int result = calculate_peach_count(n);
    printf("%d\n", result);
    return 0;
}
