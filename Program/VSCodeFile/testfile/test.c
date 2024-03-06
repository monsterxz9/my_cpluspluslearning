/* #include <stdio.h>
#include <math.h>
long long factorial(n)
{   
    int res=1;
    for(int i=1,i<=n,i++)
    {
        res*=i;
    }
    return res;
}
double item(int i)
{   
    int n=2*i-1;
    res=pow()/factorial(n);
    
    return res
}
int main()
{   
    double sum;
    for(int i=1;i<=20,i++)
    sum+=item(i);
    printf("%lf",sum)
    return 0;
}
 */
#include <stdio.h>
#include <math.h>

long long factorial(int n)
{   
    long long res = 1;,
    for(int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

double item(int i)
{   
    int n = 2 * i - 1;
    double res = pow(-1, i - 1) / factorial(n);
    
    return res;
}

int main()
{   
    double x, sum = 0;
    printf("Enter the value of x in radians: ");
    scanf("%lf", &x);

    for(int i = 1; i <= 20; i++)
    {
        sum += item(i) * pow(x, 2 * i - 1);
    }

    printf("sin(%lf) = %lf\n", x, sum);

    return 0;
}
