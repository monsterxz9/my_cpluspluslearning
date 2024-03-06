#include <stdio.h>

// 判断是否为质数的函数
int is_prime(int n) {
    if (n < 2) {
        return 0;  // 不是质数
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;  // 不是质数
        }
    }
    return 1;  // 是质数
}

int main() {
    char word[101];
    scanf("%s", word);

    int letter_count[26] = {0};  // 用于统计每个字母的出现次数

    // 统计字母出现次数
    for (int i = 0; word[i] != '\0'; ++i) {
        letter_count[word[i] - 'a']++;
    }

    // 计算最大和最小次数
    int max_count = 0, min_count = 2147483647;  // 初始化一个较大的值
    for (int i = 0; i < 26; ++i) {
        if (letter_count[i] > max_count) {
            max_count = letter_count[i];
        }
        if (letter_count[i] > 0 && letter_count[i] < min_count) {
            min_count = letter_count[i];
        }
    }

    // 判断是否为 Lucky Word
    if (is_prime(max_count - min_count)) {
        printf("Lucky Word\n%d\n", max_count - min_count);
    } else {
        printf("No Answer\n0\n");
    }

    return 0;
}
