#include <stdio.h>
int main()
{
    float m,h;
    float bmi;
    scanf("%f %f",&m,&h);
    bmi=m/h/h;
    if (bmi<18.5)
    {
        printf("Underweight");
    }
    else if (bmi>=18.5 && bmi<24)
    {
        printf("Normal");
    }
    else if (bmi>=24)
    {
        char buffer[20]; // 定义一个足够大的字符数组来存储结果的字符串表示
        snprintf(buffer, sizeof(buffer), "%.4f", bmi); // 将浮点数格式化为字符串

        // 手动处理字符串，确保最后一位不为零
        int len = strlen(buffer);
        while (len > 0 && buffer[len - 1] == '0') {
            buffer[len - 1] = '\0'; // 去掉末尾的零
            len--;
        }

        printf("%s\nOverweight", buffer); // 输出处理后的字符串
        //printf("%.4g \nOverweight",bmi);
    }
    



    return 0;
}