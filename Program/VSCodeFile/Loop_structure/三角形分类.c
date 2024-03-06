// #include <stdio.h>
// int main()
// {
//     int a,b,c,temp;
//     scanf("%d%d%d",&a,&b,&c);
//     if (a==b && b==c)
//     {
//         printf("Acute triangle\nIsosceles triangle\nEquilateral triangle\n");
//         return 0;
//     }
//     // 比较并交换第一个和第二个数
//     if (a > b) {
//         temp = a;
//         a = b;
//         b = temp;
//     }

//     // 再次比较并交换第二个和第三个数
//     if (b > c) {
//         temp = b;
//         b = c;
//         c = temp;
//     }
//     if (a+b<=c)
//     {
//         printf("Not triangle\n");
//     }
//     else if(a+b>c)
//     {
//         if(a==b)
//         {
//             if(a*a+b*b==c*c)
//             {
//             printf("Right triangle\nIsosceles triangle\n");
//             }
//             else if(a*a+b*b>c*c)
//             {
//                 printf("Acute triangle\nIsosceles triangle\n");
//             }
//             else if(a*a+b*b<c*c)
//             {
//                 printf("Obtuse triangle\nIsosceles triangle\n");
//             }
//         }
//         else if(a!=b)
//         {
//             if(a*a+b*b==c*c)
//             {
//                 printf("Right triangle\n");
//             }
//             else if(a*a+b*b<c*c)
//             {
//                 printf("Acute triangle\n");
//             }
//             else if(a*a+b*b>c*c)
//             {
//                 printf("Obtuse triangle\n");
//             }
//         }
//     }


//     return 0;
// }

#include <stdio.h>
#include <algorithm>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int sides[3] = {a, b, c};
    std::sort(sides, sides + 3);

    if (sides[0] + sides[1] <= sides[2]) {
        printf("Not triangle\n");
    } else {
        if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
            printf("Right triangle\n");
        }

        if (sides[0] * sides[0] + sides[1] * sides[1] > sides[2] * sides[2]) {
            printf("Acute triangle\n");
        }

        if (sides[0] * sides[0] + sides[1] * sides[1] < sides[2] * sides[2]) {
            printf("Obtuse triangle\n");
        }

        if (sides[0] == sides[1] || sides[1] == sides[2]) {
            printf("Isosceles triangle\n");
        }

        if (sides[0] == sides[1] && sides[1] == sides[2]) {
            printf("Equilateral triangle\n");
        }
    }

    return 0;
}
