// #include <stdio.h>
// int main()
// {
//     int (a,b,c);
//     scanf("%d%d%d",a,b,c)
//     if (a>=b && b>=c && )
//     {
//         printf("%d%d%d",c,b,a);
//     }
//     else if (a>=b && b<c)
//     {
//         printf("%d%d%d",b,c,a);
//     }
//     else if (c>=b && b>=a)
//     {
//         /* code */
//     }
//     else if (c>=b && b<a && a)
//     {
//         /* code */
//     }
//     else if (b>=a && a>=c)
//     {
//         /* code */
//     }
//     else if (/* condition */)
//     {
//         /* code */
//     }
    
    

//     return 0;
// }
#include <stdio.h>

int main() {
    int arr[3]; // 声明一个包含三个整数的数组
    int i, j, temp;

    // 从标准输入读取三个整数，存储到数组中
    for (i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    // 使用冒泡排序对数组进行升序排序
    for (i = 0; i < 3 - 1; i++) {
        for (j = 0; j < 3 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换数组元素
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 输出排序后的结果
    for (i = 0; i < 3; i++) {
        printf("%d", arr[i]);
        if (i < 2) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
// #include <stdio.h>

// int main() {
//     int a, b, c;
//     scanf("%d %d %d", &a, &b, &c);

//     // 使用冒泡排序对三个整数排序
//     if (a > b) {
//         int temp = a;
//         a = b;
//         b = temp;
//     }
//     if (b > c) {
//         int temp = b;
//         b = c;
//         c = temp;
//     }
//     if (a > b) {
//         int temp = a;
//         a = b;
//         b = temp;
//     }

//     printf("%d %d %d\n", a, b, c);

//     return 0;
// }
