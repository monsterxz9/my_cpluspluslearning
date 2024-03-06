#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // 输入评委人数

    int scores[1000];  // 定义一个数组来存储评委的分数
    int sum = 0;       // 用于计算总分的变量
    int min_score = 11, max_score = -1;  // 用于记录最低分和最高分的变量

    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);  // 输入每位评委的分数

        // 更新总分、最低分和最高分
        sum += scores[i];
        if (scores[i] < min_score) {
            min_score = scores[i];
        }
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    // 计算去掉一个最低分和一个最高分后的总分
    int adjusted_sum = sum - min_score - max_score;

    // 计算最后得分并输出，保留两位小数
    double final_score = (double)adjusted_sum / (n - 2);
    printf("%.2lf\n", final_score);

    return 0;
}
