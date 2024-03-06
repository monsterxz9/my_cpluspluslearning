//
// Created by Mark Tween on 2023/12/22.
//
/*
int findKthPositive(int* arr, int arrSize, int k){
    int i=0,j=1;
    while (i<arrSize){
        if(arr[i]==j){
            i++;
        } else {
            if(!--k)return j;
        }
        j++;
    }//暴力解法
    return j+k-1;
}*/
int findKthPositive(int* arr, int arrSize, int k){
    if(arr[0]>k)return k;
    int left=0,right=arrSize;
    while(left<right)
    {
        int mid=(left+right)/2;
        if (arr[mid]-mid-1>=k){
            right=mid;
        } else{
            left=mid+1;
        }
    }
    return k-(arr[left-1]-(left-1)-1)+arr[left-1];
}