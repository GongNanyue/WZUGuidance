#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    switch (a)
    {
    case 1:
{        double b;
        cin>>b;
        printf("%.2lf\n",b*b*3.14);}
        break;
    case 2:
{        double b,c;
        cin>>b>>c;
        printf("%.2lf\n",b*c);}
        break;
    case 3:
{        double b;
        cin>>b;
        printf("%.2lf\n",b*b);}
        break;
    default:
        printf("Invalid Data!\n");
        break;
    }
}
