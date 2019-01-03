#include <stdio.h>
int main()
{
    unsigned short x,newx,logicruler,m,n,a,b;
    printf("输入x（16进制）、m（0~15）和n（1~16-m）：\n ");/*判断m、n的值是否在合理范围内*/
    scanf("%hx%hu%hu",&x,&m,&n);
    if(m>=0&&m<=15&&n>=1&&n<=16-m)
    {
        // a = (1 << (m + n)) - 1; 处理逻辑尺调试用
        // b = (1 << (m + 1)) - 1; 处理逻辑尺调试用
        logicruler = ((1 << (m + n)) - 1) - ((1 << m) - 1);//逻辑尺
        // printf("%hu %hu\n",a,b); 调试用
        // printf("%hu\n",logicruler); 调试用
        newx = (x & logicruler) << (16 - m - n);//挪到最左边（高位对齐）
        printf("%hx", newx);//注意unsigned short配合%hu输出
    }
    else
        printf("输入错误！\n");
    return 0;
}
