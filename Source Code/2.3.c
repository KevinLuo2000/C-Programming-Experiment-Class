#include <stdio.h>
int main()
{
    int count=0;
    iteration: count++;
    printf("%d ",count);
    if(count<=5)
        goto iteration;
    printf("%d",count);
    return 0;
}
