// #include <stdio.h>
// int main()
// {
//     int n,digit,ret;
//     scanf("%d",&n);
//     while (n!=0)
//     {
//         digit = n%10;
//         printf("%d",digit);
//         ret = ret*10 + digit;
//         n/=10;
//     }
//     printf("%d",ret);
//     return 0;
// }
#include <stdio.h>
#include <stdbool.h>

// 函数用于反转整数
int reverse_int(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}

int main() {
    int N;
    scanf("%d", &N);  // 输入整数 N

    int reversed = reverse_int(N);  // 调用函数反转整数

    printf("%d\n", reversed);

    return 0;
}
