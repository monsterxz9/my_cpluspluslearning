// #include <stdio.h>
// int main()
// {
//     int L,num;
//     scanf("%d",&L);
//     for (int i = 2; i++)
//     {
//         for (int t= 2; t < i; t++)
//         {
//             if (i%t!=0)
//             {
                
//             }
            
//         }
//         do
//         {
//             /* code */
//         } while ();
        
//     }
    




//     return 0;
// }





// #include <stdio.h>

// // 判断一个数是否是质数
// int isPrime(int num) {
//     if (num <= 1) {
//         return 0; // 0和1不是质数
//     }

//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0) {
//             return 0; // 如果能被小于等于其平方根的整数整除，不是质数
//         }
//     }

//     return 1; // 否则是质数
// }

// int main() {
//     int L;
//     scanf("%d", &L);

//     if (L <= 0) {
//         printf("无效的输入。\n");
//         return 1;
//     }
    
//     int count = 0;int a=0;
//     int num = 2; // 从2开始寻找质数
//     while (count < L) {
//         if (isPrime(num)) {
//             printf("%d\n", num);
//             count+=num;
//             a++;
//         }
//         num++;
//     }
//     printf("%d",a);

//     return 0;
// }
#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    if (num % 2 == 0) {
        return 0;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int L;
    scanf("%d", &L);
    
    int sum = 0;
    int count = 0;
    int current = 2;
    
    while (sum + current <= L) {
        if (is_prime(current)) {
            sum += current;
            count++;
            printf("%d\n", current);
        }
        current++;
    }
    
    printf("%d\n", count);
    
    return 0;
}
