#include <stdio.h>
int main()
{
    int n,a,b;
    scanf("%d",&n);
    if (n%2==0)
    {
        a=1;
    }
    else if (n%2!=0)
    {
        a=0;
    }
    if (n<=12 && n>4)
    {
       b=1;
    }
    else if (n>12 && n<=4)
    {
        b=0;
    }
    if (a==1 && b==1)
    {
        printf("1 1 0 0");
    }
    else if (a==1 && b==0)
    {
        printf("0 1 1 0");
    }
    else if (a==0 && b==1)
    {
        printf("0 1 1 0");
    }
    else if (a==0 && b==0)
    {
        printf("0 0 0 1");
    }

    return 0;
}