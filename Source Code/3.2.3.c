//
// Created by Kevin Luo on 2018/11/15.
//
#include <stdio.h>
long fibonacci(int n);
void main(void)
{
    int i,k;
    long sum=0,*p=&sum;
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        sum+=fibonacci(i);
        printf("i=%d\tthe sum is %ld\n",i,*p);
    }
}
long fibonacci (int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

