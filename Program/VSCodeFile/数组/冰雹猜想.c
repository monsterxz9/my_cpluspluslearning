#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* sequence = (int*)malloc(sizeof(int)); // 初始分配一个整数的内存空间
    if (sequence == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    int count = 0;

    while (n != 1) {
        sequence[count++] = n;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        // 每次迭代动态增加内存空间
        sequence = (int*)realloc(sequence, (count + 1) * sizeof(int));
        if (sequence == NULL) {
            printf("内存分配失败\n");
            return 1;
        }
    }

    sequence[count++] = 1;  // 添加最后的1

    // 倒序输出整个变化序列
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", sequence[i]);
    }

    free(sequence); // 释放动态分配的内存

    return 0;
}




/* 
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // 数组的大小
    printf("请输入数组的大小：");
    scanf("%d", &n);

    // 使用malloc函数动态分配内存
    int *myArray = (int *)malloc(n * sizeof(int));


    if (myArray == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    // 可以像操作普通数组一样使用myArray，例如赋值和访问元素
    for (int i = 0; i < n; i++) {
        myArray[i] = i * 2;
    }

    // 输出数组的内容
    printf("数组的内容：\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", myArray[i]);
    }

    // 释放动态分配的内存
    free(myArray);

    return 0;
}
*/

/* 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",n);
    int i;
    
    while (n!=1)
    {       
        if (n%2==0)
        {
            n=n/2;
        }
        else if (n%2!=0)
        {
            n=3*n+1;
        }
    }
    



    return 0;
}
 */