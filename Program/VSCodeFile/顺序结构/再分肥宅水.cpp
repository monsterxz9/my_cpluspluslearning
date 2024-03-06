#include <stdio.h>

int main() 
{
    double t;int n;// 输入 t 和 n
    scanf("%lf %d", &t, &n);
    
    double per_student_drink = t / n;  // 每名同学可以获得的饮料数量（毫升）
    int total_cups = 2 * n;  // 总共需要的杯子数量
    
    
    printf("%.3lf\n", per_student_drink);// 输出结果
    printf("%d\n", total_cups);
    
    return 0;
}
