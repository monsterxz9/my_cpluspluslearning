/* #include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initial(int n);
void forgive(int *array, int n);

int main() {
    int num;
    scanf("%d", &num);
    initial(num);
}

void initial(int n) {   
    int size = (int)pow(2, n);
    int *array = (int *)malloc(size * size * sizeof(int));

    if (array == NULL) {
        printf("内存分配失败\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i * size + j] = 1; // 为数组赋值
        }
    }

    forgive(array, n);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", array[i * size + j]);
        }
        printf("\n");
    }

    free(array);
}

void forgive(int *array, int n) {
    if (n == 1) {
        return; // 递归终止条件
    }

    int size = (int)pow(2, n);
    int halfSize = size / 2;
    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            array[i * size + j] = 0; // 修改数组元素
        }
    }
    
    forgive(array, n - 1);
} */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initial(int n);
void forgive(int *array, int n, int startX, int startY, int totalSize);

int main() {
    int num;
    scanf("%d", &num);
    initial(num);
}

void initial(int n) {   
    int size = (int)pow(2, n);
    int *array = (int *)malloc(size * size * sizeof(int));

    if (array == NULL) {
        printf("内存分配失败\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i * size + j] = 1; // 为数组赋值
        }
    }
    // 调用递归函数时

    forgive(array, n, 0, 0, size);


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", array[i * size + j]);
        }
        printf("\n");
    }

    free(array);
}

void forgive(int *array, int n, int startX, int startY, int totalSize) {
    if (n == 0) {
        return; // 递归终止条件
    }

    int size = (int)pow(2, n - 1); // 当前递归层次的矩阵大小
    // 赦免左上角的矩阵
    for (int i = startX; i < startX + size; i++) {
        for (int j = startY; j < startY + size; j++) {
            array[i * totalSize + j] = 0;
        }
    }

    // 递归处理剩下的三个矩阵
    forgive(array, n - 1, startX + size, startY, totalSize); // 右上角
    forgive(array, n - 1, startX, startY + size, totalSize); // 左下角
    forgive(array, n - 1, startX + size, startY + size, totalSize); // 右下角
}

