#include <stdio.h>
int main()
{   
    int n,firenum,stonenum;

    scanf("%d%d%d",&n,&firenum,&stonenum);
    // 定义位置数组并将初始值赋值为0
    int location[103][103];
    for (int i = 0; i < 103; i++)
    {
        for (int j = 0; j < 103; j++)
        {
            location[i][j]=0;
        }
    }
    int x[firenum],y[firenum];
    // 火把位置用俩数组表示
    for (int i = 0; i < firenum; i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    for (int i = 0; i < firenum; i++)
    {
        for (int j = 0; j < firenum; j++)


        location[x[i]+2][y[i]+2]++;

        location[x[i]+3][y[i]+2]++;
        location[x[i]+4][y[i]+2]++;
        location[x[i]+2][y[i]+3]++;
        location[x[i]+2][y[i]+4]++;

        location[x[i]+2][y[i]+1]++;
        location[x[i]+2][y[i]]++;
        location[x[i]+1][y[i]+2]++;
        location[x[i]][y[i]+2]++;

        location[x[i]+1][y[i]+1]++;
        location[x[i]+3][y[i]+3]++;
        location[x[i]+3][y[i]+1]++;
        location[x[i]+1][y[i]+3]++;

    }

    // 判断石头是否存在
    if (stonenum!=0)
    {
        int o[stonenum],p[stonenum];
        for (int i = 0; i < stonenum; i++)
        {
            scanf("%d%d",&o[i],&p[i]);
        }
        for (int i = 0; i < stonenum; i++)
        {
            for (int j = 0; j < stonenum; j++)
                for (int k = p[i]; k <=p[i]+4; k++)
                {
                    for (int s = o[i]; s <=o[i]+4 ; s++)
                    {
                        location[s][k]++;
                    }   
                }   
        }   
    }
    int count=0;
    for (int i = 3; i <n+3; i++)
    {
        for (int j = 3; j < n+3; j++)
        {
            if (location[i][j]!=0)
            {
                count++;
            }
        }
        
    }
    printf("%d",n*n-count);
    return 0;
}



/* 已AC 学到的内容是开大点数组 读取小的来避免边界问题 */