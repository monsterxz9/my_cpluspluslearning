#include <stdio.h>
int main()
{
    int n;
    int count=0;
    scanf("%d",&n);
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                // 交换 num[j] 和 num[j+1]
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {   int s=0;
        for (int j = 1; j < i; j++)
        {
            for (int k = 0; k <j ; k++)
            {   
                if (num[i]==num[j]+num[k])
                {   s=1;
                    count++;
                }
                if (s>0)
                {
                    break;
                }
                                
            }
            if (s>0)
                {
                    break;
                }        
        }
        if (s>0)
        {
            continue;
        }
         
    }  
    
    printf("%d",count);
    return 0;
}