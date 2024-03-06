#include <stdio.h>
#include <stdlib.h>
typedef struct Students {
    char *name;
    int chi;
    int math;
    int eng;
    int total;
} stu;

int main() {
    int num;
    scanf("%d", &num);

    stu *a[num];
    for (int i = 0; i < num; i++) {
        a[i] = malloc(sizeof(stu)); // 为每个学生分配内存
        if (a[i] == NULL) {
            printf("内存分配失败\n");
            return 1;
        }

        a[i]->name = malloc(100 * sizeof(char));  // 分配内存以存储名字
        if (a[i]->name == NULL) {
            printf("内存分配失败\n");
            return 1;
        }

        scanf("%9s", a[i]->name);
        scanf("%d", &a[i]->chi);
        scanf("%d", &a[i]->math);
        scanf("%d", &a[i]->eng);
        a[i]->total = a[i]->chi + a[i]->math + a[i]->eng;
    }

    int highestIndex = 0;
    for (int i = 1; i < num; i++) {
        if (a[i]->total > a[highestIndex]->total) {
            highestIndex = i;
        }
    }

    printf("%d %s %d %d %d %d\n", highestIndex + 1, a[highestIndex]->name, a[highestIndex]->chi, a[highestIndex]->math, a[highestIndex]->eng, a[highestIndex]->total);

    // 释放内存
    for (int i = 0; i < num; i++) {
        free(a[i]->name);
        free(a[i]);
    }

    return 0;
}