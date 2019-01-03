//
// Created by Kevin Luo on 2018/11/22.
//
#include <stdio.h>
#include <math.h>
#define S ((a+b+c)/2.0)
#define AREA (sqrt(S*(S-a)*(S-b)*(S-c)))
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%f %f\n",S,AREA);
    return 0;
}
