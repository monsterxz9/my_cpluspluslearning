#include <stdio.h>
int main()
{
    int n;
    int min=0;
    scanf("%d",&n);
    for ( int i= 1; i <= n; i++)
    {
        int num;
        scanf("%d",&num);
        if (i==1 || num<min)
        {
            min=num;
        }
        
    }
    printf("%d",min);



    return 0;
}