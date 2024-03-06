//
// Created by Mark Tween on 2023/12/27.
//
#include <stdio.h>
#define INF 210000000
#define N 4

int min(int a, int b){
    return a > b ? b : a;
}

void floyd(int matrix[N][N], int n){
    for (int k = 0; k < n; ++k)    //一共需要执行K轮
        for (int i = 0; i < n; ++i)   //i和j从0开始就行了，直接全看，不会影响结果的
            for (int j = 0; j < n; ++j)
                matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);   //按照规则更新就行了
}

int main(){
    int matrix[N][N] = {{0, 1, INF, INF},
                        {4, 0, INF, 5},
                        {INF, 2, 0, INF},
                        {3, INF, 7, 0}};

    floyd(matrix, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%d  ", matrix[i][j]);
        putchar('\n');
    }
}