/**
 * File: insertion_sort.c
 * Created Time: 2022-12-29
 * Author: Listening (https://github.com/L-Super)
 */

#include "../include/include.h"

/* �������� */
void insertionSort(int nums[], int size) {
    // ��ѭ����base = nums[1], nums[2], ..., nums[n-1]
    for (int i = 1; i < size; i++)
    {
        int base = nums[i], j = i - 1;
        // ��ѭ������ base ���뵽��ߵ���ȷλ��
        while (j >= 0 && nums[j] > base)
        {
            // 1. �� nums[j] �����ƶ�һλ
            nums[j + 1] = nums[j]; 
            j--;
        }
        // 2. �� base ��ֵ����ȷλ��
        nums[j + 1] = base; 
    }
}

/* Driver Code */
int main() {
    int nums[] = {4, 1, 3, 1, 5, 2};
    insertionSort(nums, 6);
    printf("����������ɺ� nums = ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
