// #include <stdio.h>
// int main()
// {
//     int k,n;
//     scanf("%d",&k);
//     for (int i = 0;i<n;i++)
//     {
//         n++;
//         if ((n+2)*(n+1)/2>k)
//         {
//             break;
//         }
        
//     }
//     printf("%d",n*(n+1)*(2*n+1)/6+(k-(n+3)*n/2)*(n+1));



//     return 0;
// }
#include <stdio.h>

int main() {
    int k, n;
    scanf("%d", &k);

    n = 1;
    while (1) {
        
        if ((n + 2) * (n + 1) / 2 >= k) {
            break;
        }
        n++;
    }

    int sum = n * (n + 1) * (2 * n + 1) / 6 + (k - n* (n + 1) / 2) * (n + 1);
    printf("%d\n", sum);

    return 0;
}
