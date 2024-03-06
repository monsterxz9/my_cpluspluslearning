#include <stdio.h>
int main()
{
    int n,k;
    int a=0; int b=0;
    int sum1=0;int sum2=0;
    float shang1,shang2;
    scanf("%d%d",&n,&k);
    for ( int i=1 ; i<= n; i++)
    {
        if (i%k==0)
        {
            a++;
            sum1=sum1+i;
        }
        else if (i%k!=0)
        {
            b++;
            sum2=sum2+i;
        }
        
    }
    shang1=(float)sum1/a;
    shang2=(float)sum2/b;
    printf("%.1f %.1f",shang1,shang2);




    return 0;
}