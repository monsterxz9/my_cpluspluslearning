#include <stdio.h>

int main() {
    double t;
    int n;

    // ���� t �� n
    scanf("%lf %d", &t, &n);

    double per_student_drink = t / n;  // ÿ��ͬѧ���Ի�õ�����������������
    int total_cups = 2 * n;  // �ܹ���Ҫ�ı�������

    // ������
    printf("%.3lf\n", per_student_drink);
    printf("%d\n", total_cups);

    return 0;
}
