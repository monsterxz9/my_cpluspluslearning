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

        scanf("%99s", a[i]->name);
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
/* typedef struct Students
{
    char * name;
    int chi;
    int math;
    int eng;
    int total;
}stu;

int main() {
    int num;
    scanf("%d", &num);

    stu *a[num];
    for (int i = 0; i < num; i++) {
        a[i]->name = malloc(9 * sizeof(char));  // 假设名字长度不超过 99 个字符
        if (a[i]->name == NULL) {
            // 处理内存分配失败的情况
            printf("内存分配失败\n");
            return 1;
        }

        scanf("%9s", a[i]->name);  // 读取姓名
        scanf("%d", &a[i]->chi);    // 读取语文成绩
        scanf("%d", &a[i]->math);   // 读取数学成绩
        scanf("%d", &a[i]->eng);    // 读取英语成绩
        a[i]->total=a[i]->chi+a[i]->math+a[i]->eng;
    }
    int item=0;
    for (int i = 0; i < num-1; ++i) {
        if (a[i]->total<a[i+1]->total)
        item=i+1;
    }
    printf("%d %s %d %d %d",item+1,a[item]->name,a[item]->chi,a[item]->math,a[item]->eng);
    return 0;
} */
/* 结构体指针的内存分配:您声明了一个结构体指针数组 stu *a[num];，但您没有为每个指针分配内存来存储 stu 结构体的实例。您应该在循环中为每个指针分配内存。
应使用 a[i] = malloc(sizeof(stu)); 来分配内存 */
/* 寻找总分最高的学生:在循环中，您正在比较每对相邻学生的总分。但是，您没有在发现更高分数时更新 item 变量。应该在找到更高分数时更新 item。
内存释放: */
/*程序结束前，应释放为每个学生分配的内存。 */