//
// Created by Kevin Luo on 2018/12/25.
//
#include <stdio.h>
struct T{
    int x;
    char c;
    char *t;
} y={10,'A',"Hello"};
int main()
{
    printf("%x\n%x\n%x\n",&(y.x),&(y.c),&(y.t));
    return 0;
}
