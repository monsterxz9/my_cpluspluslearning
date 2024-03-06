/* #include <stdio.h>

int main() {
    int num[200][200];
    int count=0; // 用于记录当前行数

    for (int i = 0; i < 200; i++) {
        
        for (int j = 0; j < 200; j++)
        {
            scanf("%d", &num[i][j]);
            count++;
            if (getchar() == '\n') 
            {    
                break;
            }
        }
        if (count==i)
        {
            break;
        }
    }

    printf("%d ", count);
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            int count1=0;
            if (num[i][j]==num[i+1][j+1])
            {
                count1++;
            }
            else if (num[i][j]!=num[i+1][j+1])
            {
                printf("%d ",count1);
                break;
            }
        }
    }
    
    return 0;
}
 */
#include <stdio.h>
#include <string.h>

int main() {
    char matrix[200][200];
    int N = 0; // 用于记录矩阵的行数

    // 读取输入矩阵并确定N的大小
    while (scanf("%s", matrix[N]) == 1) {
        N++;
    }

    // 初始化压缩码
    int compressedCode[2 * 200 + 1]; // 最多可能有2*N个数字
    int codeIndex = 0;
    compressedCode[codeIndex++] = N;

    // 计算行的压缩码
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; matrix[i][j] != '\0'; j++) {
            if (matrix[i][j] == '0') {
                count++;
            } else {
                if (count > 0) {
                    compressedCode[codeIndex++] = count;
                }
                count = 0;
            }
        }
        if (count > 0) {
            compressedCode[codeIndex++] = count;
        }
    }

    // 计算列的压缩码
    for (int j = 0; matrix[0][j] != '\0'; j++) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (matrix[i][j] == '1') {
                count++;
            } else {
                if (count > 0) {
                    compressedCode[codeIndex++] = count;
                }
                count = 0;
            }
        }
        if (count > 0) {
            compressedCode[codeIndex++] = count;
        }
    }

    // 输出压缩码
    for (int i = 0; i < codeIndex; i++) {
        printf("%d ", compressedCode[i]);
    }
    printf("\n");

    return 0;
}
