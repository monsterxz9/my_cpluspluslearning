#include <stdio.h>
#include <ctype.h>
int main()
{
    // 定义一个字符数组，用于存储输入的字符串
    char input_str[101];

    // 读取输入字符串
    scanf("%s", input_str);

    // 遍历字符串并将小写字母转换为大写字母
    for (int i = 0; input_str[i] != '\0'; ++i) {
        input_str[i] = toupper(input_str[i]);
    }

    // 输出结果
    printf("%s\n", input_str);
    return 0;
}