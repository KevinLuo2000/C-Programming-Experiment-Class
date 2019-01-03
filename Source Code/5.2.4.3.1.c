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
void sort(int _score[],int _n)
{
    int i,j;
    char t[1001];
    for(i=0;i<_n;i++)
    {
        for(j=0;j<_n-i;j++)
        {
            if(_score[j]<_score[j+1])
            {
                swap(&_score[j],&_score[j+1]);
                strcpy(t,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],t);
            }
        }
    }
}
#include <stdio.h>
int data[1001];
int middle;


int binary_search(int a[],int key,int l,int r)
{
    if(l<=r) {
        middle = (l + r) >> 1;
        // printf("%d",middle);
        if (a[middle] == key) {
            return middle;
        }
        else if (a[middle] < key) {
            return binary_search(a, key, l, middle - 1);
        }
        else if (a[middle] > key) {
            return binary_search(a, key, middle + 1, r);
        }
    }
    else
        return -1;//返回在最后
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s",name[i]);
        scanf("%d", &score[i]);
    }
    sort(score,n);
    for(i=0;i<n;i++)
    {
        printf("%-20s ",name[i]);
        printf("%d\n",score[i]);
    }
    printf("\n");
    int N,num;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d", &num);
        if(binary_search(score,num,1,n)!=-1)
            printf("%s%d\n",name[binary_search(score,num,1,n)],score[binary_search(score,num,1,n)]);
        else
            printf("Not found!\n");
    }
    return 0;
}
