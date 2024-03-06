#include <stdio.h>
typedef struct Student
{
    int id;
    int age;
    char *name;
}Student;
int main()
{
    Student student= {1,23,"xiaohong"};
    Student *p=&student;
    printf("%d",p->age);
}
