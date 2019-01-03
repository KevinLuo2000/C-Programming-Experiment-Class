//
// Created by Kevin Luo on 2018/12/3.
//
#include <stdio.h>
int queen[8],count;
int valid(int row,int column)
{
    int i;
    for(i=0;i<row;i++)
    {
        if(queen[i]==column) return 0;
        if(row-i==column-queen[i]) return 0;
        if(row-i==-column+queen[i]) return 0;
    }
    return 1;
}
void scan(int queennum)
{
    int i;
    for(i=0;i<=7;i++)
    {
        if(valid(queennum,i))
        {
            queen[queennum]=i;
            if(queennum==7) {
                int j;
                count++;
                printf("第%d组结果：\n",count);
                for(j=0;j<=7;j++)
                    printf("(%d,%d); ",j,queen[j]);
                printf("\n");
                return;
            }
            scan(queennum+1);
        }
    }
}
int main()
{
    scan(0);
    return 0;
}