#include <stdio.h>
void yanghuitriangle(int num)
{   int a[21][21];
    for (int i=1;i<=num;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i<=2)
            {
                a[i][j]=1;
            }
            if(i>2 && (j>1 || j<i))
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
            if(i>2 &&(j==1 || j==i))
            {
                a[i][j]=1;
            }
        }
    }
        for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    yanghuitriangle(num);
    return 0;
}