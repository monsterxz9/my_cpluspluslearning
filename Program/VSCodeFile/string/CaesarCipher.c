#include <stdio.h>

int main() {
    // 获取输入
    int n;
    scanf("%d", &n);

    // 定义字符数组，用于存储原文字符串
    char original_str[51];
    
    // 读取原文字符串
    scanf("%s", original_str);

    // 遍历原文字符串的每个字符
    for (int i = 0; original_str[i] != '\0'; ++i) {
        // 将字符向后移动n位，并循环
        char char_out = 'a' + (original_str[i] - 'a' + n) % 26;
        
        // 输出密码字符
        printf("%c", char_out);
    }

    printf("\n");

    return 0;
}
