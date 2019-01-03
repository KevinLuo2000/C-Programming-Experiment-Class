//
// Created by Kevin Luo on 2018/12/29.
//
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[100];
    gets(s);
    FILE *fp;
    fp = fopen("test.txt","w");
    // int i=0;
    char * sen =s;
    //对行首第一个字母进行特殊判断
    {
        if (*sen >= 'a' && *sen <= 'z')
        {
            char ch = (*sen++) - 'a' + 'A';
            fputc(ch, fp);
        }
        else
            fputc(*sen++, fp);
    }
    while(*sen!='\0')
    {
        if(*(sen-1)==' ' && *sen>='a'&&*sen<='z')//判断需要转换的标准：该字符前一个字符为空格（确保该字符为单词首字母）且该字符为小写字母
        {
            char ch = (*sen++)-'a'+'A';
            fputc(ch,fp);
        }
        else
            fputc(*sen++,fp);
    }
        //i++;
    fclose(fp);
    return 0;
}
