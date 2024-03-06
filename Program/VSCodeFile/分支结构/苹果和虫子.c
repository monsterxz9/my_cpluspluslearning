#include <stdio.h>
int main()
{   
    int m,t,s;
    int n,b;
    scanf("%d %d %d",&m,&t,&s);
    if (t==0)
    {
        printf("0");
    }
    else if (t!=0)
    {
        if (s>=m*t)
        {
            printf("0");
        }
        else if (s<m*t)
        {
            if (s%t==0)
            {
                n=m-s/t;
                printf("%d",n);
            }
            else if (s%t!=0)
            {   b=(int)(s/t);
                n=m-b-1;
                printf("%d",n);
            }
            
        }
    }
    return 0;
}