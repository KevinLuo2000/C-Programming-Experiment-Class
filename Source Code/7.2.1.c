//
// Created by Kevin Luo on 2018/12/22.
//
#include <stdio.h>
int main()
{
    char u[]="UVWXYZ";
    char v[]="xyz";
    struct T{
        int x;
        char c;
        char *t;
    } a[]={{11, 'A', u},{100, 'B', v}},*p=a;
    printf("%c",(*(++p)->t));//地址访问用->，元素值访问用.
    return 0;
}
