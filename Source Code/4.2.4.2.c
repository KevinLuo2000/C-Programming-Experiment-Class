//
// Created by Kevin Luo on 2018/11/22.
//
#include <stdio.h>
#define CHANGE 0
int main()
{
    char e;
    while(e=getchar(),e!='\n')
    {
#if CHANGE==0
        printf("%c",e);
#endif
#if CHANGE==1

        if(e>=65&&e<=90)
            printf("%c",e-'A'+'a');
        else if(e>=97&&e<=122)
            printf("%c",e-'a'+'A');
        else
            printf("%c",e);
#endif
    }
    printf("\n");
    return 0;
}