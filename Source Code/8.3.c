#include <stdio.h>
int main()
{
    short a=0x253d;
    char ch;
    FILE *fp;
    fp=fopen("data.bin","wb+");//打开二进制文件,可读写
    fwrite(&a,sizeof(char),1,fp);//将a的数据写入二进制文件data
    rewind(fp); //将文件的位置指针复位到文件首部
    while((ch = fgetc(fp)) != EOF)//一个字节一个字节地读，以char型输出
        putchar(ch);
    putchar('\n');
    fclose(fp);//关闭文件
    return 0;
}
