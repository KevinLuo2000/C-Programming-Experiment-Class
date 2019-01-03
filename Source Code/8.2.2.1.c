#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    char ch;
    FILE *fp;
    if(argc!=3){
        printf("Arguments error!\n");
        exit(-1);
    }
    if((fp=fopen(argv[2],"r"))==NULL){        /* fp 指向 filename */
        printf("Can't open %s file!\n",argv[2]);
        exit(-1);
    }

    while(ch=fgetc(fp)!=EOF)          /* 从filename中读字符 */
        putchar(ch);                  /* 向显示器中写字符 */
    fclose(fp);                      /* 关闭filename */
    return 0;
}
