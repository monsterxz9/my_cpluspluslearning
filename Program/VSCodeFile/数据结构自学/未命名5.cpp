#include <stdio.h>

int main(void) {
    float salary;

    printf("\aEnter your desired monthly salary: $");
    scanf("%f", &salary);

    printf("\n\t$%.2f a month is $%.2f a year.\n", salary, salary * 12.0);
    printf("\aGee!\n");

    return 0;
}

