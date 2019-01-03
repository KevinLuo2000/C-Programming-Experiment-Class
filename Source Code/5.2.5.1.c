#include <stdio.h>
void strnins(char s[],char t[],int n)
{
    int j=0;
    while(t[j])
        j++;
    int j_last=j;
    int i=n;
    j=0;
    while(t[j])
    {
        s[i+j_last]=s[i];
        s[i++]=t[j++];
    }
    printf("%s",s);
}
int main()
{
    char a[101],b[101];
    int N;
    scanf("%s%s%d",a,b,&N);
    strnins(a,b,N);
    return 0;
}