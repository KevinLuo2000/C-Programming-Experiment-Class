//
// Created by Kevin Luo on 2018/12/12.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * strjoint(const char * s1, const char *s2)
{
    char *s3=(char *)malloc(sizeof(char)*50);
    //memset(s3, '\0', sizeof(*s3));
    //s3=(char *)s1;
    //printf("%lu\n",strlen(s1));
    int i=0;
    while(*(s1+i)!='\0')
    {
        *(s3+i) = *(s1+i);
        i++;
    }
    i=0;
    while(*(s2+i)!='\0')
    {
        *(s3+strlen(s1)+i) = *(s2+i);
        i++;
    }
    *(s3 + strlen(s1) + i)='\0';
    return s3;
}
int main()
{
    char *(*p[2])(const char *,const char *);
    p[0]=strjoint;
    p[1]=strstr;//strstr等函数名可理解为一个地址，故p[1]前面无需加* 判断是否子串，是:返回子串在母串开始的地址;否:返回(null)
    char *str1,*str2;
    str1=(char *)malloc(sizeof(char)*50);
    str2=(char *)malloc(sizeof(char)*50);
    scanf("%s%s",str1,str2);
    int i;
    for(i=0;i<2;i++)
        printf("%s\n",p[i](str1,str2));//1.调用函数指针时无需加* 2.strstr类型为char *, 而%s正好接受字符串首地址，相吻合
    return 0;
}
