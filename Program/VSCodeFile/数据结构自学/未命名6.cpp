#include <stdio.h>

int main() {
    long s;
    int v,min,a,b;
   

    scanf("%ld%d", &s, &v);
    min=s/v;
    if (min<470)
    {
        a=(470-min)/60;
        b=(470-min)%60;
        if (b>=10)
        {
            printf("%d:%d",a,b);
        }
        else if (b<10)
        {
            printf("%d:0%d",a,b);  
        }
        
    }
    else if (min>=470)
    {
        min=min-470;
        a=(470-min)/60;
        b=(470-min)%60;
        if (a>=10 && b>=10)
        {
           printf("%d:%d",a,b);
        }
        else if (a>=10 && b<10)
        {
           printf("%d:0%d",a,b);
        }
        else if (a<10 && b<10)
        {
           printf("0%d:0%d",a,b);
        }
        else if (a<10 && b>=10)
        {
            printf("0%d:%d",a,b);
        }
        
        
        
    }
    


    return 0;
}

