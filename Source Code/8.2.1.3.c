#include <stdio.h>
int main(void)
{
    // 本人机器是以小端模式进行存储的，即数据的高字节保存在内存的高地址中，数据的低字节保存在内存的低地址中。
    // 以short型变量a举例，0x253f占两字节，在写入内存（二进制文件同理）时先将低字节3f写入，
    // 16进制下3f对应的ascii字符为?，25对应的ascii字符为%，故倘以char型输出写入内存的结果，得到的是?%。
    // 而txt文本文件相当于以字符（串）形式存储写入进去的每一个数据，故所见即所得。

    short a=0x253f,b=0x7b7d;//两个十六进制short类型数，各占两字节
    char ch;
    FILE *fp1,*fp2;
    fp1=fopen("d:\\abc1.bin","wb+");//打开二进制文件,可读写
    fp2=fopen("d:\\abc2.txt","w+");//打开txt文本文件，可读写
    fwrite(&a,sizeof(short),1,fp1);//将a的数据写入二进制文件abc1
    fwrite(&b,sizeof(short),1,fp1);//将b的数据写入二进制文件abc1
    fprintf(fp2,"%d %d",a,b);//将a与b的数据以short型十六进制数的形式写入文本文件abc2

    rewind(fp1); rewind(fp2);//将两文件的位置指针复位到文件首部
    while((ch = fgetc(fp1)) != EOF)
        putchar(ch);//一个字节一个字节地读，以char型输出
    putchar('\n');

    while((ch = fgetc(fp2)) != EOF)
        putchar(ch);//一个字节一个字节地读，以char型输出
    putchar('\n');

    fclose(fp1);//关闭文件
    fclose(fp2);
    return 0;
}
