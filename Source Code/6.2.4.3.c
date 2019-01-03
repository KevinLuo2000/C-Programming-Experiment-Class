//
// Created by Kevin Luo on 2018/12/13.
//
#include <stdio.h>
#include <stdlib.h>
int data[101];
int* sort(int * num,int m,char * para,int paranum)
{
    //bubble sort
    int i,j,t;
    if(paranum==1)//无参数
    {
        for(i=0;i<m;i++)
        {
            for (j = 0; j < m - i - 1; j++)
            {
                if (*(num + j) > *(num + j + 1))
                {
                    t = *(num + j);
                    *(num + j) = *(num + j + 1);
                    *(num + j + 1) = t;
                }
            }
        }
    }
    // printf("%s %d",para,paranum);
    if(paranum==2&&para[0]=='-'&&para[1]=='d')//有-d参数
    {
        for(i=0;i<m;i++)
        {
            for (j = 0; j < m - i - 1; j++)
            {
                if (*(num + j) < *(num + j + 1))
                {
                    t = *(num + j);
                    *(num + j) = *(num + j + 1);
                    *(num + j + 1) = t;
                }
            }
        }
    }
    if(paranum>2||(paranum==2&&(para[0]!='-'||para[1]!='d')))//处理参数错误的exception
    {
        printf("参数输入有误");
        exit(0);//直接退出程序
    }
    return num;
}
int main(int argc,char* argv[])
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&data[i]);
    int * (*choose)(int *num,int m,char * para,int paranum);//指向函数的指针（函数指针）
    choose=sort;
    int *p = choose(data,n,argv[1],argc);
    // printf("%c",argv[1][0]);
    while(n--)
        printf("%d ",*p++);
    return 0;
}
