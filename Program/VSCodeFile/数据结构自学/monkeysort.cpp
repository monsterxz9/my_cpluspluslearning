#include <iostream>
#include <cstdlib> // 为rand()和srand()添加
#include <ctime>   // 为time()添加
using namespace std;

bool checkOrder(int arr[], int size){
    for (int i = 0; i < size - 1; ++i)
        if(arr[i] > arr[i + 1]) return false;
    return true;
}

int main(){
    int arr[] = {3, 5, 7, 2, 9, 0, 6, 1, 8, 4}, size = 10;

    srand(time(NULL)); // 初始化随机数生成器
    int counter = 0;
    while (true) {
        int a = rand() % size, b = rand() % size;
        swap(arr[a], arr[b]); // 直接交换元素
        if(checkOrder(arr, size)) break;
        counter++;
    }
    printf("在第 %d 次排序完成！", counter);
}
