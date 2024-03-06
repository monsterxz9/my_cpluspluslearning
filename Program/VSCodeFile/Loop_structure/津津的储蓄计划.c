#include <stdio.h>
int main()
{
    int budget,n,saved;
    n=0;
    int s=0;
    saved=0;
    
    for (int i = 1; i <=12; i++)
    {
        scanf("%d",&budget);
        n=300+n-budget;
        if (n>=100)
        {   
            int a=0;
            a=n/100*100;
            saved=a+saved;
            n=n-a;
        }
        else if (n<0)
        {
            printf("-%d",i);
            return 0;
        }
        
    }
    s=(int)(1.2*saved+n);
    printf("%d",s);



    return 0;
}