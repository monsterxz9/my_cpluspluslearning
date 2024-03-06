#include <stdio.h>

int main() {
    int n;
    double sum = 0.0;

    scanf("%d", &n);

    while (1)
    {
        int i=1;
        sum += 1.0 / i;
        i++;
        if (sum>n)
        {
            printf("%d",i);
            break;
        }
        
    
    }
     
   


    return 0;
}
