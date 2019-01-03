#include <stdio.h>
int main()
{
    unsigned int x,ruler,a,b,c,d;
    scanf("%u",&x);
    ruler=(1<<8)-1;//逻辑尺
    a=ruler&x;//取出最低八位
    b=((ruler<<8)&x)>>8;//取出次低八位
    c=((ruler<<16)&x)>>16;//取出次高八位
    d=((ruler<<24)&x)>>24;//取出最高八位
    printf("%u.%u.%u.%u",a,b,c,d);//由低位到高位输出
    return 0;
}
