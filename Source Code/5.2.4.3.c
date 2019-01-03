//
// Created by Kevin Luo on 2018/11/28.
//
#include <stdio.h>
#include <string.h>
int score[101];
char name[101][21];
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void sort(int _score[],int _name[],int _n)
{
    int i,j;
    char t[];
    for(i=0;i<_n;i++)
    {
        for(j=0;j<_n-i;j++)
        {
            if(_score[j]<_score[j+1])
            {
                swap(&_score[j],&_score[j+1]);
                strcpy(t,_name[j]);
                strcpy(_name[j],_name[j+1]);
                strcpy(t_name[j],t);
            }
        }
    }
}
int main()
{
    memset(a,-1,sizeof(int) * 101);
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s",name[i]);
        scanf("%d", &score[i]);
    }
    sort(score,name,n);
    for(i=0;i<n;i++)
    {
        printf("%-20s ",name[i]);
        printf("%d\n",score[i]);

    }
    printf("\n");
    //int N,num;
    //scanf("%d",&N);
    /*while(N--)
    {
        scanf("%d", &num);
        if(a[num]>=0)
        {
            printf("%-20s ",name[a[num]]);
            printf("%d\n",num);
        }
        else
            printf("Not found!\n");
    }*/
    return 0;
}
