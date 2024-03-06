// #include <stdio.h>
// int main()
// {
//     int a,b;
//     a=101;
//     b=a/100*100;
//     printf("%d",b);



//     return 0;
// }
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int current_num = 1;

    // 外循环控制行数
    int i=n;
   while (i!=0) {
        // 内循环控制每行的数字
        for (int j = 1; j <= i; j++) {
            // 格式化输出为2位数
            printf("%02d", current_num);
            current_num++;
        }
        printf("\n"); // 换行
        i--;
    }

    return 0;
}
