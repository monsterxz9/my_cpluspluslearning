// #include <stdio.h>
// int main()
// {
//     int n,i,a,b,c;
//     scanf("%d",&n);
//     for ( i = 1; i <=n; i++)
//     {
//         if (i==1)
//         {
//             for (int j = 1; j <=n; j++)
//             {
//                 printf("0%d",j);               
//             }
//             printf("\n");
//         }
//         else if (i>1)
//         {
//             if ((i-1)*n+1<10 && i*n<10)
//             //第i行第一个和最后一个元素大小与10做比较
//             {   
//                 for (a=i;a<=i*n;a++)
//                 {
//                     printf("0%d",(a-1)*n+1);               
//                 }
//                 printf("\n");
//             }
//             else if ((i-1)*n+1<10 && i*n>=10)
//             {
//                 do
//                 {
//                     printf("0%d",(i-1)*n+1); 
//                 } while (i==10);
                
//                 for ( c = 10; c <=i*n; c++)
//                 {
//                     printf("%d",c);
//                 }
//                 printf("\n");
//             }
//             else if ((i-1)*n+1>=10)
//             {
                
//                 for ( b=i; i <=n; b++)
//                 {
//                     printf("%d\n",(b-1)*n+1);               
//                 }
//             }
//         }   
//     }
    



//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int n, i;
//     scanf("%d", &n);

//     for (i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (i * n + j < 10) {
//                 printf("0%d", i * (n-1) + j);
//             } else {
//                 printf("%d", i * (n-1)+ j);
//             }
            
//         }
//         printf("\n");
//     }

//     return 0;
// }
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // 打印矩形
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%02d", num);
            num++;
        }
        printf("\n");
    }

    printf("\n"); // 打印空行

    // 打印正方形
    num = 1;
    for (int i = 1; i <= n; i++) {
        // 打印空格
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }

        // 打印数字
        for (int j = 1; j <= i; j++) {
            printf("%02d", num);
            num++;
        }
        printf("\n");
    }

    return 0;
}
