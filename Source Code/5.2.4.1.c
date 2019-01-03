//
// Created by Kevin Luo on 2018/11/28.
//
#include <stdio.h>
int a[3][4];
int main()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(j=0;j<4;j++) {
        for (i = 0; i < 3; i++) {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
