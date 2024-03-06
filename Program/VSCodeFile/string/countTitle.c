#include <stdio.h>

int main() {
    char c;
    int count = 0;

    while (1) {
        scanf("%c", &c);

        // 判断是否到达行末或文件末
        if (c == '\n' || c == EOF) {
            break;
        }

        // 如果不是空格，则计数加一
        if (c != ' ') {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
