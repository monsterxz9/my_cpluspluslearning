#include <stdio.h>

int main() {
    int winning_numbers[7];
    int n;
    int prizes[7] = {0}; // 初始化中奖等级统计
    // 读取小明买的彩票数量
    scanf("%d", &n);

    // 读取中奖号码
    for (int i = 0; i < 7; i++) {
        scanf("%d", &winning_numbers[i]);
    }



    // 逐张彩票判断中奖情况
    for (int i = 0; i < n; i++) {
        int ticket[7];
        int matching_numbers = 0;

        // 读取小明的彩票号码
        for (int j = 0; j < 7; j++) {
            scanf("%d", &ticket[j]);
        }

        // 判断匹配的号码数量
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                if (ticket[j] == winning_numbers[k]) {
                    matching_numbers++;
                    break;
                }
            }
        }

        // 根据匹配的号码数量确定中奖等级
        if (matching_numbers == 7) {
            prizes[0]++;
        } else if (matching_numbers == 6) {
            prizes[1]++;
        } else if (matching_numbers == 5) {
            prizes[2]++;
        } else if (matching_numbers == 4) {
            prizes[3]++;
        } else if (matching_numbers == 3) {
            prizes[4]++;
        } else if (matching_numbers == 2) {
            prizes[5]++;
        } else if (matching_numbers == 1) {
            prizes[6]++;
        }
    }

    // 输出中奖情况
    for (int i = 0; i < 7; i++) {
        printf("%d ", prizes[i]);
    }

    return 0;
}
