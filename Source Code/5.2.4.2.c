//
// Created by Kevin Luo on 2018/11/28.
//
#include <stdio.h>
int main()
{
    int number;
    char digit[101];
    scanf("%d",&number);
    int mask=1;
    int i=sizeof(int)*8-1;
    while(i)
    {
        digit[i]=((number&mask)>>(sizeof(int)*8-1-i))+'0';
        i--;
        // printf("%c",digit[i]);
        mask=mask<<1;
    }
    digit[0]=(number>=0?0:1)+'0';
    digit[sizeof(int)*8]='\0';
    //printf("%c  ",digit[0]);
    printf("%s\n",digit);
    return 0;
}
