#include <stdio.h>
#include <math.h>
double f(double x)
{
    return 3*x*x*x-4*x*x-5*x+13;
}
double df(double x) {
    return 9 * x * x - 8 * x - 5;
}
double x1,x2;
int main()
{
    x1=3;
    while(fabs(x2-x1)>1e-6) {
        x1=x2;
        x2 = x1 - f(x1) / df(x1);
    }
    printf("%lf\n",x2);
    return 0;
}
