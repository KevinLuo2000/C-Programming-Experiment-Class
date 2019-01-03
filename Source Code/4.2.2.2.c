#include <stdio.h>//1
#define max ((a>b?a:b)>c?(a>b?a:b):c)
float sum(float x, float y);//3
void main(void)
{
    int a, b, c;
    float d, e;
    printf("Enter three integers:");
    scanf("%d%d%d",&a,&b,&c);//4
    printf("\nthe maximum of them is %d\n",max);

    printf("Enter two floating point numbers:");
    scanf("%f%f",&d,&e);//5
    printf("\nthe sum of them is  %f\n",sum(d,e));
}
float sum(float x, float y)
{
    return x+y;
}
