//
// Created by Mark Tween on 2023/12/16.
//


#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct stack {
    E *array;
    int capacity;
    int top;
};
typedef struct stack *ArrayStack;

_Bool initStack(ArrayStack stack) {
    stack->array = malloc(sizeof(E) * 20);
    if (stack->array == NULL) return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}
_Bool PushStack(ArrayStack stack, E element)
{
    if(stack->top+1==stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        E *newArray = realloc(stack->array, newCapacity * sizeof(E));
        if (newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[stack->top+1]=element;
    stack->top++;
    return 1;
}
void printStack(ArrayStack stack){
    printf("| ");
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d, ", stack->array[i]);
    }
    printf("\n");
}
int find(const int *num,int size,int element)
{   for(int i=0;i<size;i++)
    {   if(num[i]==element) return i;
    }
    return -1;
}
int *extend(const int *nums,int size,int enlarge)//使用const声明数组防止其被改变
{
    int *res=(int *) malloc(sizeof(int)*(size+enlarge));
    for (int i = 0; i < size; ++i) {
        res[i]=nums[i];
    }
    for (int i = size; i <size+enlarge ; ++i) {
        res[i]=0;
    }
    return res;
}

int main() {
    struct stack stack;
    initStack(&stack);
    for (int i = 0; i < 20; ++i) {
        PushStack(&stack, i);
    }
    printStack(&stack);
    return 0;
}

