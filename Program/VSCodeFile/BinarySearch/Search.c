#include <stdio.h>
#include <stdlib.h>
int binarySearchFirst(int array[], int n, int target) {
    int left = 0, right = n - 1, result = -2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] >= target) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int *arr;
    arr=malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int *mptr;
    mptr=malloc(sizeof(int)*m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&mptr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d ",binarySearchFirst(arr,n,mptr[i])+1);
    }
    free(arr);  // Free allocated memory
    free(mptr); // Free allocated memory
    return 0;
}
