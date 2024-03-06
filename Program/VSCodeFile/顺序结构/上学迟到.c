#include <stdio.h>

int main() {
    long s;
    int v,a,b;
    float min;
   

    scanf("%ld%d", &s, &v);
    min=(float)s/v;
    if (min<470)
    {
        a=(int)(470-min)/60;
        b=(int)(470-min)%60;
        if (b>=10)
        {
            printf("0%d:%d",a,b);
        }
        else if (b<10)
        {
            printf("0%d:0%d",a,b);  
        }
        
    }
    else if (min>=470)
    {
        min=1440-(min-470);
        a=(int)min/60;
        b=(int)min%60;
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
