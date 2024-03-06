/* #include <stdio.h>
#include <stdint.h>
int main() {
    int n;
    intmax_t S = 0;
    intmax_t t = 1;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        t = 1; // 重置 t 的值为 1
        for (int j = 1; j <= i; j++) {
            t *= j; // 计算阶乘
        }
        S += t; // 将阶乘加到总和 S
    }

    printf("%jd", S);

    return 0;
}
 */

#include<stdio.h>
int main()
{
    int i,A[1005]={0},B[1005]={0},n,j;
    scanf("%d", &n);
    A[0]=B[0]=1;
    for (i=2;i<=n;i++){
        for (j=0;j<100;j++)
            B[j]*=i;
        for (j=0;j<100;j++)
            if (B[j]>9){
                B[j+1] += B[j]/10;
                B[j]%=10;
            }
        for (j=0;j<100;j++){
            A[j]+=B[j];
            if (A[j]>9) {
                A[j+1] += A[j]/10;
                A[j]%=10;
            }
        }
    }
    for (i=100;i>=0&&A[i]==0;i--);
    for (j=i;j>=0;j--) printf("%d", A[j]);
    return 0;
}

/* # [NOIP1998 普及组] 阶乘之和

## 题目描述

用高精度计算出 $S = 1! + 2! + 3! + \cdots + n!$（$n \le 50$）。

其中 `!` 表示阶乘，定义为 $n!=n\times (n-1)\times (n-2)\times \cdots \times 1$。例如，$5! = 5 \times 4 \times 3 \times 2 \times 1=120$。

## 输入格式

一个正整数 $n$。

## 输出格式

一个正整数 $S$，表示计算结果。

## 样例 #1

### 样例输入 #1

```
3
```

### 样例输出 #1

```
9
```

## 提示

**【数据范围】**

对于 $100 \%$ 的数据，$1 \le n \le 50$。

**【其他说明】**

注，《深入浅出基础篇》中使用本题作为例题，但是其数据范围只有 $n \le 20$，使用书中的代码无法通过本题。

如果希望通过本题，请继续学习第八章高精度的知识。 */