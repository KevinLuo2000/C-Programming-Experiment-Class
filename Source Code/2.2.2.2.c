#include <stdio.h>
int main(void)
{
    int i=1,S,s=1;
    printf("Please enter integer S:\n");
    scanf("%d",&S);
    while(s<S) {
        i++;
        s = s * i;
    }
    printf("n = %d",i);
    return 0;
}
