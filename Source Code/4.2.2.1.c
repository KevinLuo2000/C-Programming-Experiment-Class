#include <stdio.h>//1
int max(int x, int y, int z);//2
float sum(float x, float y);//3
void main(void)
{
    int a, b, c;
    float d, e;
    printf("Enter three integers:");
    scanf("%d%d%d",&a,&b,&c);//4
    printf("\nthe maximum of them is %d\n",max(a,b,c));

    printf("Enter two floating point numbers:");
    scanf("%f%f",&d,&e);//5
    printf("\nthe sum of them is  %f\n",sum(d,e));
}

int max(int x, int y, int z)
{
    int t=0;//4
    if (x>y)
        t=x;
    else
        t=y;
    if (t<z)
        t=z;
    return t;
}

float sum(float x, float y)
{
    return x+y;
}
