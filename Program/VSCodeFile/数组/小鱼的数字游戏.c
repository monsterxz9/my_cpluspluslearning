#include <stdio.h>
int main()
{
    int a[100];
    int num=1;
    int i=0;
    while (1)
    {
        scanf("%d",&num);
        if (num==0)
        {
            break;
        }
        a[i]=num;
        i++;
        
    }
    for (int j = i-1; j >=0; j--)
    {
        printf("%d ",a[j]);
    }
    return 0;
}