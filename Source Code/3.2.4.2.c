//
// Created by Kevin Luo on 2018/11/11.
//
#include <stdio.h>
#include <math.h>
int i,_count,j;
int is_prime(int x)
{
    _count=0;
    if(x==1)
        return 0;
    if(x==2)
        return 1;
    if(x==3)
        return 1;
    for(i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            _count++;
    }
    if(!_count)
        return 1;
    else return 0;
}
int main()
{
    int begin,end,count=1,k;
    while(scanf("%d%d",&begin,&end)!=EOF)
    {
        printf("GOLDBACH'S CONJECTURE:\n"
               "Every even number n>=4 is the sum of two primes:\n");
        for(j=begin%2?begin+1:begin;j<=end;j+=2)
        {
            for(k=1;k<=j/2;k++)
            {
                if(is_prime(k)&&is_prime(j-k)) {
                    printf("%d=%d+%d\n", j, k, j - k);
                    break;
                }
            }
        }
        count++;
        printf("\n");
    }
    return 0;
}
