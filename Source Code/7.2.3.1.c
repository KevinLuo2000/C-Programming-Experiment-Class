//
// Created by Kevin Luo on 2018/12/23.
//
#include <stdio.h>
struct bits
{
    unsigned int bit0:1,bit1:1,bit2:1,bit3:1,bit4:1,bit5:1,bit6:1,bit7:1;
};
union bits_union{//union成员共享同一段内存，故在输入c的同时也即拆分成了八个bit位
    unsigned char c;
    struct bits _bits;
}u;
void f0(struct bits b)
{
    printf("the function %d is called!\n",b.bit0);
}
void f1(struct bits b)
{
    printf("the function %d is called!\n",b.bit1);
}
void f2(struct bits b)
{
    printf("the function %d is called!\n",b.bit2);
}
void f3(struct bits b)
{
    printf("the function %d is called!\n",b.bit3);
}
void f4(struct bits b)
{
    printf("the function %d is called!\n",b.bit4);
}
void f5(struct bits b)
{
    printf("the function %d is called!\n",b.bit5);
}
void f6(struct bits b)
{
    printf("the function %d is called!\n",b.bit6);
}
void f7(struct bits b)
{
    printf("the function %d is called!\n",b.bit7);
}

int main()
{
    unsigned int n;
    void (*p_fun[8])(struct bits b);//函数指针数组
    scanf("%d",&n);
    u.c=n;//将unsigned int转化为unsigned char型储存

    //创建p_fun与函数名（地址）的映射关系
    p_fun[0]=f0;
    p_fun[1]=f1;
    p_fun[2]=f2;
    p_fun[3]=f3;
    p_fun[4]=f4;
    p_fun[5]=f5;
    p_fun[6]=f6;
    p_fun[7]=f7;
    if(u._bits.bit0)
        p_fun[0](u._bits);
    if(u._bits.bit1)
        p_fun[1](u._bits);
    if(u._bits.bit2)
        p_fun[2](u._bits);
    if(u._bits.bit3)
        p_fun[3](u._bits);
    if(u._bits.bit4)
        p_fun[4](u._bits);
    if(u._bits.bit5)
        p_fun[5](u._bits);
    if(u._bits.bit6)
        p_fun[6](u._bits);
    if(u._bits.bit7)
        p_fun[7](u._bits);
    return 0;
}
