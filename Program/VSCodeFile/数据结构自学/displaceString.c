#include <stdio.h>

int main() {
    char a[6];
    printf("请输入你要输出的字符:\n");
    for (int i = 0; i < 6; i++) {
        scanf(" %c", &a[i]); // 注意前面有一个空格，用于跳过任何空白字符
        a[i] += 4;
    }
    for (int i = 0; i < 6; i++) {
        printf("%c", a[i]);
    }
    return 0;
}
/* #include <stdio.h>
int main()
{
    char a[6];
    printf("请输入你要输出的字符:\n");
    for (int i = 0; i < 5; i++){
        scanf("%c", &a[i]);
        (int)a[i];
        a[i] += 4;
    }
    for (int i = 0; i < 5; i++){
        printf("%c", a[i]);
        return 0;
    }
}
 */