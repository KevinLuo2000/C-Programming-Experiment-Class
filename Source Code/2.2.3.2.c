#include <stdio.h>
int main()
{
    int N,bool;
    char c;
    scanf("%d",&N);
    getchar();
    while(N--)
    {
        bool=0;
        while((c=getchar())!='\n')
        {
            if (c==' '&&(!bool)) {
                bool++;
                printf(" ");
            }
            if (c!=' ')
            {
                bool=0;
                printf("%c", c);
            }
        }
        printf("\n");
    }
}
