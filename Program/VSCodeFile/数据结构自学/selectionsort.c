#include <stdio.h>
#include <stdlib.h>

void sort (int *nums,int n)
{
    // 外循环：未排序区间为 [i, n-1]
    for (int i = 0; i < n - 1; i++) {
        // 内循环：找到未排序区间内的最小元素
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[k])
                k = j; // 记录最小元素的索引
        }
        // 将该最小元素与未排序区间的首个元素交换
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
}
void printArray(int *nums,int numsize)
{
    for (int i = 0; i < numsize; i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}
int main()
{   
    int numsize=10;
    int *nums=malloc(sizeof(int)*numsize);
    for (int i = 0; i < numsize; i++)
    {
        nums[i]=rand()%100+13;
    }
    printArray(nums,numsize);
    sort(nums,numsize);
    printArray(nums,numsize-1);
    free(nums);
    return 0;
}