#include <stdio.h>//1
#include <assert.h>//2
#define R
int integer_fraction(float x);
void main(void)
{
    float  r,s;
    int s_integer=0;
    printf ("input a number: ");
    scanf("%f",&r);
#ifdef R
    s=3.14159*r*r;
    printf("area of round is: %f\n",s);
    s_integer= integer_fraction(s);
    printf("the integer fraction of area is %d\n", s_integer);
    assert((s-s_integer)<1.0);
#endif
}

int integer_fraction(float x)
{
    int i=x;
    return i;
}
