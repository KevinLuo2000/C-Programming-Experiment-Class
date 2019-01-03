#include <stdio.h>
#include <stdlib.h>
// 指针未赋初值，导致野指针/悬空指针的出现，可能会导致意料不到的后果
int main(void)
{
    float *p=(float *)malloc(sizeof(float));
    scanf("%f",p);
    printf("%f\n",*p);
}
