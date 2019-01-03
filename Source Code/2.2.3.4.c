#include <stdio.h>
int main()
{
    long long m;
    int remainder;
    while(scanf("%lld",&m),m)
    {
        while(m)
        {
            remainder=m%10;
            printf("%d",remainder);
            m/=10;
        }
        printf("\n");
    }
    return 0;
}
