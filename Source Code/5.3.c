//
// Created by Kevin Luo on 2018/11/29.
//
#include <stdio.h>
int data[1001];
int middle;
int binary_search(int a[],int key,int l,int r)
{
    if(l>r)
        return -1;

    middle = (l + r) >> 1;

    if (a[middle] == key) {
        return middle;
    }
    else if (a[middle] > key) {
        return binary_search(a, key, l, middle - 1);
    }
    else if (a[middle] < key) {
        return binary_search(a, key, middle + 1, r);
    }

}
int main()
{
    int n,i,target;
    scanf("%d%d",&n,&target);
    for(i=1;i<=n;i++)
        scanf("%d",&data[i]);
    printf("%d",binary_search(data,target,1,n));
    return 0;
}
