#include <stdio.h>
int main()
{
    int y,m,a;
    scanf("%d%d",&y,&m);
    if (y%100==0)
    {
       if (y%400==0)
       {
        a=1;
       }
       else if (y%400!=0)
       {
        a=0;
       }
    }
    else if (y%100!=0)
    {
        if (y%4==0)
        {
            a=1;
        }
        else if (y%4!=0)
        {
            a=0;
        }
        
    }
    if (m==1 || m==3 || m==5  || m==7 || m==8 || m==10 || m==12)
    {
        printf("31");
    }
    else if (m==4 || m==6 || m==9 || m==11)
    {
        printf("30");
    }
    else if (m==2)
    {
        if (a==1)
        {
            printf("29");
        }
        else if (a==0)
        {
            printf("28");
        }
        
    }
    

    return 0;
}