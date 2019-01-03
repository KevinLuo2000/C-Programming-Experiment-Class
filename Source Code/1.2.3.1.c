#include <stdio.h>
int main()
{
    char c;
    scanf("%c",&c);
    c = (c>='A'&&c<='Z')?(c-'A'+'a'):c;
    printf("%c",c);
    return 0;
}
