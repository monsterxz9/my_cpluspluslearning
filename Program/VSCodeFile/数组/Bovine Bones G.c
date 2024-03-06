#include <stdio.h>
int main()
{
    int s1,s2,s3;
    scanf("%d%d%d",&s1,&s2,&s3);
    // 排序s1s2s3
    if (s1 > s2) {
        int temp = s1;
        s1 = s2;
        s2 = temp;
    }
    if (s1 > s3) {
        int temp = s1;
        s1 = s3;
        s3 = temp;
    }
    if (s2 > s3) {
        int temp = s2;
        s2 = s3;
        s3 = temp;
    }  
    int num;
    num=s1+s2+s3-2; 
    int arr1[s1],arr2[s2],arr3[s3];
    // 为arr数组赋值
    for (int i = 0; i < s1; i++)
    {
        arr1[i]=i+1;
    }
    for (int i = 0; i <s2; i++)
    {
        arr2[i]=i+1;
    }
    for (int i = 0; i < s3; i++)
    {
        arr3[i]=i+1;
    }
    // 初始化结果为0
    int result[80]={0};
    // 各个数相加
    for (int i = 0; i < s3; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            for (int k = 0; k < s1; k++)
            {
                int sum=0;
                sum=arr1[k]+arr2[j]+arr3[i];
                result[sum-3]++;
            }
        }
    }
    int max_value = result[0]; // 假设第一个元素是最大值
    int max_index = 0;     // 最大值的序号

    for (int i = 1; i < num; i++) {
        if (result[i] > max_value) {
            max_value = result[i]; // 更新最大值
            max_index = i;      // 更新最大值的序号
        } else if (result[i] == max_value && i < max_index) {
            max_index = i;      // 如果有相同的最大值且较小，更新序号
        }
    }
    printf("%d",max_index+3);
    return 0;
}