//
// Created by Kevin Luo on 2018/11/14.
//
#include <stdio.h>
void gcd(int m,int n)
{
    if(!(m%n)||!(n%m))
    {
        printf("%d\n", m <= n ? m : n);
        return;
    }
    if(m>=n)
        m%=n;
    else
        n%=m;
    gcd(m,n);
}
int main()
{
    int M,N;
    while (scanf("%d%d",&M,&N),M)
        gcd(M,N);
    return 0;
}
