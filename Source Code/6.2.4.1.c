//
// Created by Kevin Luo on 2018/12/11.
//
#include <stdio.h>
long number;
int main()
{
    scanf("%ld",&number);
    char *p=(char *)&number;//此处指针p定义为char型，目的在于方便指针移动（因char型占一字节，高低四位处理完正好处理了一个字节），亦方便最后输出结果。
    p+=3;
    int up_half,low_half;
    int i;
    for(i=1;i<=4;i++) {
        low_half = (*p) & 15;
        up_half = ((*p) >> 4) & 15;
        if (low_half >= 10)
            low_half = low_half - 10 + 'A';
        else if (low_half < 10)
            low_half += '0';
        if (up_half >= 10)
            up_half = up_half - 10 + 'A';
        else if (up_half < 10)
            up_half += '0';
        p--;
        printf("%c %c",up_half,low_half);
        if(i!=4)
            printf(" ");
    }
    return 0;
}
