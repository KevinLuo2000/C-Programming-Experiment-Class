//
// Created by Kevin Luo on 2018/9/27.
//
//有括号包围：
#include <stdio.h>
#define A (-2+2)
int main()
{
    printf("%d",!A);
    return 0;
}

//无括号包围：
#include <stdio.h>
#define A -2+2
int main()
{
    printf("%d",!A);
    return 0;
}
