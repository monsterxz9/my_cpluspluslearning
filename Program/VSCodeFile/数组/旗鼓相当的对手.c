#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N;
    scanf("%d",&N);
    int chinese[N];
    int math[N];
    int english[N];
    int sum[N];
    int count=0;
    for (int i = 0; i <N; i++)
    {
       scanf("%d %d %d",&chinese[i],&math[i],&english[i]);
       sum[i]=chinese[i]+math[i]+english[i];
    }
    for (int i =0; i <N; i++)
    {
        for (int j = i+1; j <N; j++)
        {
            if (abs(sum[i]-sum[j])<=10 
             && abs(chinese[i]-chinese[j])<=5 
             && abs(math[i]-math[j])<=5 
             && abs(english[i]-english[j])<=5)
            {
                count++;
            }
            
        }
        
    } 
    printf("%d",count);
    return 0;
}