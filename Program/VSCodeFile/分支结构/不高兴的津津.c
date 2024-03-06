// #include <stdio.h>
// int main()
// {
//     int i=1;
//     int a,b,c;
//     int hour[7];
//     do
//     {   
//         scanf("%d%d",&a,&b);
//         hour[]=a+b;
//         i++;
//     } while (i>7);
    
    


//     return 0;
// }

// // #include <stdio.h>

// int main() {
//     int array[] = {10, 5, 8, 20, 15};
//     int n = sizeof(array) / sizeof(array[0]); // 数组的大小

//     int max = array[0]; // 假设第一个元素最大
//     int min = array[0]; // 假设第一个元素最小
//     int maxIndex = 0;   // 记录最大值的索引
//     int minIndex = 0;   // 记录最小值的索引

//     // 遍历数组，比较元素大小并记录索引
//     for (int i = 1; i < n; i++) {
//         if (array[i] > max) {
//             max = array[i];
//             maxIndex = i;
//         }
//         if (array[i] < min) {
//             min = array[i];
//             minIndex = i;
//         }
//     }

//     // 输出最大值和对应的编号
//     printf("最大值：%d，对应的编号：%d\n", max, maxIndex);

//     // 输出最小值和对应的编号
//     printf("最小值：%d，对应的编号：%d\n", min, minIndex);

//     return 0;
// }
#include <stdio.h>

int main() {
    int max_unhappiness = 0;
    int unhappiest_day = 0;

    for (int day = 1; day <= 7; day++) {
        int school_hours, mom_hours;
        scanf("%d %d", &school_hours, &mom_hours);

        int total_hours = school_hours + mom_hours;
        if (total_hours > 8 && total_hours > max_unhappiness) {
            max_unhappiness = total_hours;
            unhappiest_day = day;
        }
    }

    printf("%d\n", unhappiest_day);

    return 0;
}
