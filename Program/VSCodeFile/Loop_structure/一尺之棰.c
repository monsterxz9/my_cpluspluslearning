#include <stdio.h>
int main()
{
    int a;
    int i=1;
    scanf("%d",&a);
    
    while (a!=1)
    {
        i++;
        a=a/2;
    }
    
    printf("%d",i);



    return 0;
}
