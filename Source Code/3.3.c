#include <stdio.h>
int with_return(int m)
{
    return m;
}
void without_return(int n)
{
    n++;
    printf("%d",n);
    return;
}
int main()
{
    int number=112;
    printf("%d\n",with_return(number));
    without_return(number);
    return 0;
}
