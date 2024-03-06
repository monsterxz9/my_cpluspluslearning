#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int num[n * n];
    int maxnum=0;
    int sumnum=0; 

    for (int i = 0; i < n * n; i++) {
        scanf("%d", &num[i]);
        sumnum+=num[i];
        maxnum++;
        if (sumnum==n*n)
        {
            break;
        }
        
    }

    int count = 0; // 用于记录当前行已经输出的字符数

    for (int i = 0; i < maxnum; i++) {
        if (i % 2 == 0) {
            for (int j = 1; j <= num[i]; j++) {
                printf("0");
                count++;
                if (count % n == 0) {
                    printf("\n");
                }
            }
        } else if (i % 2 == 1) {
            for (int j = 1; j <= num[i]; j++) {
                printf("1");
                count++;
                if (count % n == 0) {
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
