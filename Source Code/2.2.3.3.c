#include <stdio.h>
int main()
{
    int n,i,j,k,number,count=0;
    while(scanf("%d",&n),n)
    {
        //if(!count)

        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(j==0)
                {
                    number=1;
                    for(k=1;k<=2*(n-i-1);k++)
                        printf(" ");
                    printf("%4d",number);
                }
                else
                {
                    number*=(float)(i-j+1)/j;
                    if(number/100)
                        printf(" ");
                    else if(number/10)
                        printf("  ");
                    else
                        printf("   ");
                    printf("%d",number);
                }
                //%04d,补0
            }
            printf("\n");
        }
        //count++;
        printf("\n");
    }
    return 0;
}
