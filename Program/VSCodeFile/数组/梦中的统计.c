#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int count[10] = {0}; // 初始化一个包含10个元素的计数数组，初始值都为0

    for (int num = M; num <= N; num++) {
        int temp = num; // 临时变量保存当前处理的数字
        while (temp > 0) {
            int digit = temp % 10; // 获取当前数字的最后一位
            count[digit]++; // 更新计数数组
            temp /= 10; // 去掉最后一位
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    return 0;
}




/* #include <stdio.h>
int function()
{
    int count[10]={0};
    int a,b;
    int digit[10];
    for ( int i = 0; i <10; i++)
    {
        digit[i]=i;
    }
    
    while (a%10!=0)
    {
        b=a%10;
        a/=10;
        for (int i = 0; i < 10; i++)
        {
            if (b==digit[i])
            {
                count[i]++;
            }
            
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",count[i]);
    }
    return 0;
}
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    int count[10]={0};
    int diff=N-M;int number[diff];
    for (int i = 0; i < diff; i++)
    {
        scanf("%d",&number[i]);
    }

    
    return 0;

} */