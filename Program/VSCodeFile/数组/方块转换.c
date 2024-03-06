#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char num[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c",&num[i][j]);
        }
    }
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c",num[i][j]);
        }
    }
    
    return 0;
}