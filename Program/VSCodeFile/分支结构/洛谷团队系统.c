#include <stdio.h>
int main()
{
    int n,t1,t2;
    scanf ("%d",&n);
    t1=5*n;
    t2=11+3*n;
    
    
    if (t1<t2)
    {
        printf("Local");
    }
        else if (t1>=t2)
        {
            printf("Luogu");
        }
        



    return 0;
}