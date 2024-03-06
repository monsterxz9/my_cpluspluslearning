// #include <stdio.h>
// int main()
// {
//     int n,max,min,temp1,temp2;
//     temp1=0;temp2=0;
//     max=0;min=0;
//     scanf("%d",&n);
//     for (int i = 0; i < n; i++)
//     {
        
//         int a;
//         scanf("%d",&a);
//         min=a;
        
//         if (min>temp1)
//         {
//             min=temp1;
//         }
//         temp1=a;
//         max=a;
//         if (max<temp2)
//         {
//             max=temp2;
//         }    
//         temp2=a;
        
//     }
//     printf("%d",max-min);



//     return 0;
// }

#include <stdio.h>

int main() {
    int n, max,min;
    scanf("%d", &n);
    
    // 读取第一个整数并初始化 max 和 min
    scanf("%d", &max);
    min = max;
    
    for (int i = 1; i < n; i++) {
        int a;
        scanf("%d", &a);
        
        // 更新最大值和最小值
        if (a > max) {
            max = a;
        }
        if (a < min) {
            min = a;
        }
    }
    
    printf("%d", max - min);

    return 0;
}
