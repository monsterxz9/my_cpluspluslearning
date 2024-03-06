#include <stdio.h>
int main ()
{   
    int h,r,t;
    float v;
    scanf("%d%d",&h,&r);
    v=3.14*r*r*h/1000;
    t=(int)20/v+1;
    printf("%d",t);
    return 0;
}