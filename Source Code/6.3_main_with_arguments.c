//
// Created by Kevin Luo on 2018/12/12.
//
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *number[])
{
    int a = atoi(*(number+1));
    int b = atoi(*(number+2));
    printf("%d",a>b?a:b);
    return 0;
}

