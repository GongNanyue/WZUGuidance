#include <stdio.h>
int main()
{
    double PI=1;
    int n=1;
    for (int i = 1; i <= 200; i++,n++)
    {
        if(i%2==0){
            PI*=n/(n+1.0);
        }
        else
            PI*=((n+1.0)/n);
    }
    PI=PI*2;
    printf("%.3lf\n",PI);
    return 0;
}
