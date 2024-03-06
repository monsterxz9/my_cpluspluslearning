#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int magicSquare[N][N];

    // 初始化幻方
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            magicSquare[i][j] = 0;
        }
    }

    int row = 0;
    int col = N / 2;
    int num = 1;

    while (num <= N * N) {
        magicSquare[row][col] = num;
        num++;

        int next_row = (row - 1 + N) % N;
        int next_col = (col + 1) % N;

        if (magicSquare[next_row][next_col] == 0) {
            row = next_row;
            col = next_col;
        } else {
            row = (row + 1) % N;
        }
    }

    // 输出幻方
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", magicSquare[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
