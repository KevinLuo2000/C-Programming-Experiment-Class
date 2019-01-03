//
// Created by Kevin Luo on 2018/11/15.
//
#include "stdio.h"
double sum_fac(int n);
void main(void)
{
    int k;
    for(k=1;k<6;k++)
        printf("k=%d\tthe sum is %lf\n",k,sum_fac(k));
}
double sum_fac(int n)
{
    static double s=0;
    int i;
    long fac=1;
    for(i=1;i<=n;i++)
        fac*=i;
    s+=(double)1/fac;
    return s;
}
