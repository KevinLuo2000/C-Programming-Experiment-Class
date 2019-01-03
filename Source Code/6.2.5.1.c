//
// Created by Kevin Luo on 2018/12/12.
// 设有N位整数和M位小数（N=20，M=10）的数据a,b。编程计算a+b并输出结果。
// 如：12345678912345678912.1234567891 + 98765432109876543210.0123456789
// 高精度加法
//
#include <stdio.h>
#define N 20
#define M 10
int main()
{
    char a[N+M+2],b[N+M+2],sum[N+M+3];
    scanf("%s%s",a,b);
    char * pa=((char*)a)+30;
    char * pb=((char*)b)+30;
    // printf("%c",*pa);
    char * pc=((char*)sum)+31;
    int add=0,count=0;
    while(count<=30)
    {
        if(*pa=='.')
        {
            *pc='.';
            pa--;
            pb--;
            pc--;
            count++;
            continue;
        }
        // printf("%d %d",(int) *pa , (int) *pb);
        *pc = (*pa-'0' + *pb-'0' + add) % 10 + '0';
        add = (*pa-'0' + *pb-'0' + add) / 10;
        pa--;
        pb--;
        pc--;
        count++;
    }
    *pc=add+'0';
    sum[N+M+2]='\0';
    if (sum[0]=='0')
        printf("%s",sum+1);
    /*另一种方式输出
     * if (sum[0]=='0')
    {
        int i=1;
        while(sum[i]!='\0')
        {
            printf("%c",sum[i++]);
        }
    }*/
    else
        printf("%s",sum);
    return 0;
}
