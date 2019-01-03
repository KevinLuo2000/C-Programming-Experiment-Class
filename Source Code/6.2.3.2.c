#include <stdio.h>
char *_strcpy(char *,char *);
int main(void)
{
    char a[60],b[60]="there is a boat on the lake.";
    printf("%s\n",_strcpy(a,b));

}
char *_strcpy(char *s,char *t)
{
    int count=0;
    while(*s++=*t++)
        count++;
    return (s-count-1);
}
