#include <stdio.h>
int main(void)
{
    int i=1,n,s=1;
    printf("Please enter n:\n");
    scanf("%d",&n);
    do
    {
        s=s*i;
        i++;
    }
    while(i<=n);
    printf("%d! = %d",n,s);
    return 0;
}
