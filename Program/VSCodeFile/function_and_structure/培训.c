#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    int score;
};

// 函数模拟培训过程
struct Student trainStudent(struct Student student) {
    // 提升成绩，但不超过600分
    int newScore = (int)(student.score * 1.2);
    if (newScore > 600) {
        newScore = 600;
    }

    // 年龄加1
    student.age++;

    student.score = newScore;
    return student;
}

int main() {
    int n;
    scanf("%d", &n);

    // 读取学员信息
    for (int i = 0; i < n; i++) {
        struct Student student;
        scanf("%s %d %d", student.name, &student.age, &student.score);

        // 调用培训函数
        student = trainStudent(student);

        // 输出学员信息
        printf("%s %d %d\n", student.name, student.age, student.score);
    }

    return 0;
}
