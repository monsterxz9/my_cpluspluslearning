// #include <stdio.h>
// int main()
// {
//     int n,money1,money2,money3,a,b,c,d,e,f;
//     scanf("%d",&n);
//     scanf("%d %d",&a,&b);
//     scanf("%d %d",&c,&d);//a,c,e数量，b,d,f价钱
//     scanf("%d %d",&e,&f);
//     if (n%a!=0)
//     money1=(n/a+1)*b;
//     else if(n%a==0)
//     {money1=n/a*b;}
//     if (n%c!=0)
//     money2=(n/c+1)*d;
//     else if(n%c==0)
//     {money2=n/c*d;}
//     if (n%e!=0)
//     money3=(n/e+1)*f;
//     else if(n%e==0)
//     {money3=n/e*f;}
//     int max;
//     if (money1 <= money2 && money2 <= money3) {
//         max = money1;
//     } else if (money2 <= money1 && money2 <= money3) {
//         max = money2;
//     } else {
//         max = money3;
//     }
//     printf("%d",max);


//     return 0;
// }
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int packages[3][2];  // 三种包装的数量和价格
    
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &packages[i][0], &packages[i][1]);
    }
    
    int min_cost = 1000000000;  // 初始化最小花费为一个较大的值
    
    // 遍历三种包装
    for (int i = 0; i < 3; i++) {
        int quantity = packages[i][0];
        int price = packages[i][1];
        // 计算需要购买的包装数
        int packages_needed = (n + quantity - 1) / quantity;
        // 计算总花费
        int cost = packages_needed * price;
        // 更新最小花费
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    
    // 输出最小花费
    printf("%d\n", min_cost);
    
    return 0;
}
