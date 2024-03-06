#include <stdio.h>
#include <string.h>

int main() {
    char isbn[14]; // 用于存储输入的ISBN号码（包括分隔符和识别码）

    // 输入ISBN号码
    scanf("%s", isbn);

    // 去掉分隔符"-"
    char cleaned_isbn[10];
    int j = 0;
    for (int i = 0; i < strlen(isbn); i++) {
        if (isbn[i] != '-') {
            cleaned_isbn[j] = isbn[i];
            j++;
        }
    }
    cleaned_isbn[9] = '\0'; // 确保字符串末尾有终止符

    // 计算识别码
    int total = 0;
    for (int i = 0; i < 9; i++) {
        total += (cleaned_isbn[i] - '0') * (i + 1);
    }

    // 计算正确的识别码
    int checksum = total % 11;
    char correct_checksum;
    if (checksum == 10) {
        correct_checksum = 'X';
    } else {
        correct_checksum = checksum + '0'; // 转换为字符
    }

    // 检查输入的识别码是否正确
    if (isbn[12] == correct_checksum) {
        printf("Right\n");
    } else {
        // 如果不正确，输出正确的ISBN号码
        isbn[12] = correct_checksum;
        printf("%s\n", isbn);
    }

    return 0;
}
