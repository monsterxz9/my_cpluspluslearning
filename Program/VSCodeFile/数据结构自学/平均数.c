#include <stdio.h>
int main()
{
    int number,sum,count;
    count=0;
    sum=0;
    scanf("%d",&number);
    while (number!=-1)
    {
        count++;
        sum+=number;
        scanf("%d",&number);
    }
    printf("%f\n",1.0*sum/count);
}