#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int scores[n][m];

    // 读入每个同学的得分
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &scores[i][j]);
        }
    }

    double max = 0;

    // 计算每个同学的得分
    for (int i = 0; i < n; ++i) {
        int minScore = 11, maxScore = -1, totalScore = 0;
        
        // 找出最低分和最高分，并计算总分
        for (int j = 0; j < m; ++j) {
            if (scores[i][j] < minScore) {
                minScore = scores[i][j];
            }
            if (scores[i][j] > maxScore) {
                maxScore = scores[i][j];
            }
            totalScore += scores[i][j];
        }

        // 计算得分，去掉一个最低分和一个最高分
        double finalScore = (totalScore - minScore - maxScore) * 1.0 / (m - 2);

        // 更新最高得分
        if (finalScore > max) {
            max = finalScore;
        }
    }

    // 输出最高得分，保留两位小数
    printf("%.2lf\n", max);

    return 0;
}
