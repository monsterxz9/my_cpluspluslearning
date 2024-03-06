#include <stdio.h>
int main()
{
    int n,m;
    int min=90000000;
    scanf("%d %d",&n,&m);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for (int i = 0; i < n-m+1; i++)
    {   
        int sum=0;
        for (int j = i; j <i+m; j++)
        {
            sum+=a[j];
        }
        if (sum<min)
        {
            min=sum;
        }
        
    }
    printf("%d",min);
    
    return 0;
}