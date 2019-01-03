#include<stdio.h>
#define M 10
#define N 3
int a[M+1],seq,b[1001];
int main()
{
    int j=1;
    int i=1;
    while(seq<M)
    {
        if(j-1==N)
        {
            j=1;
            if((i-1)%M==0)
                a[M] = ++seq;
            else
                a[(i-1)%M] = ++seq;
        }
        if(!a[(i-1)%M+1])
            j++;
        i++;
    }
    int k;
    for(k=1;k<=M;k++)
        b[a[k]]=k;
    for(k=1;k<=M;k++)
        printf("%6d ",b[k]);
    return 0;
}
