//
// Created by Kevin Luo on 2018/11/15.
//
#include "stdio.h"
long sum_fac(int n);
void main(void)
{
    int k;
    for(k=1;k<6;k++)
        printf("k=%d\tthe sum is %ld\n",k,sum_fac(k));
}
long sum_fac(int n)
{
    static long s=0;
    static long fac=1;
    fac*=n;
    s+=fac;
    return s;
}