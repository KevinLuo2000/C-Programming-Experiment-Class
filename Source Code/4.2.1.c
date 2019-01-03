//
// Created by Kevin Luo on 2018/11/22.
//
#include "stdio.h"
#define SUM (a+b)//5
#define DIF (a-b)//6
#define SWAP(a,b)  t=a;a=b;b=t;//3
void main()//1
{
    int b,t,a;
    printf("Input two integers a, b:");
    scanf("%d%d",&a,&b);//4
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d",SUM,SUM*DIF);
    SWAP(a,b);
    printf("\nNow a=%d,b=%d\n",a,b);//2
}

