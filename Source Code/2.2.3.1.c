//If语句
#include <stdio.h>
double min(double a,double b) {
    return a < b ? a : b;
}
int main()
{
    double x,y,xori;
    while(scanf("%lf",&x),x)
    {
        xori=x;
        y=0;
        while(x>5000)
        {
            y+=0.25*min((xori-5000),1000);
            x-=1000;
        }
        if(x>4000&&x<=5000) {
            y += 0.2 * min((xori - 4000),1000);
            x -= 1000;
        }
        if(x>3000&&x<=4000) {
            y += 0.15 * min((xori - 3000),1000);
            x-=1000;
        }
        if(x>2000&&x<=3000) {
            y += 0.1 * min((xori - 2000),1000);
            x-=1000;
        }
        if(x>1000&&x<=2000) {
            y += 0.05 * min((xori - 1000),1000);
            x-=1000;
        }
        if(x<=1000) {
            y += 0;
        }
        printf("%lf\n",y);
    }
    return 0;
}

//Switch语句
#include <stdio.h>
int main()
{
    double x,y;
    int smallx;
    while(scanf("%lf",&x),x)
    {
        smallx=(int)x/1000;
        switch(smallx) {
            case 0:{
                break;
            }
            case 1: {
                y = 0.05*(x-1000);
                break;
            }
            case 2: {
                y = 0.1*(x-2000)+50;
                break;
            }
            case 3: {
                y = 0.15*(x-3000)+150;
                break;
            }
            case 4: {
                y = 0.2*(x-4000)+300;
                break;
            }
            default: {
                y = 0.25*(x-5000)+500;
            }
        }
        printf("%lf\n",y);
    }
    return 0;
}
