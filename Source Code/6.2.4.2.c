//
// Created by Kevin Luo on 2018/12/12.
//
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    char* str[101];
    int i;
    for(i=0;i<=30;i++)
        str[i]=(char*)malloc(sizeof(char)*81);
    while(scanf("%d",&n),n!=0)
    {
        getchar();
        int i;
        for(i=0;i<=n-1;i++)
        {
            gets(str[i]);
            int j=0;
            int count = 0;
            while(*(str[i]+j)!='\n')
            {
                if(*(str[i]+j)!=' ') {
                    count=0;
                    putchar(*(str[i] + j));
                }
                else if(*(str[i]+j)==' '&&!count)
                {
                    putchar(*(str[i] + j));
                    count++;
                }
                j++;
            }
            if(j)
                printf("\n");
        }
        printf("\n");
    }
    return 0;
}
