#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t t;
    cin>>t;
    for (int i=0;i<t;i+=1){
        double a,b,c;
        cin>>a>>b>>c;
        if (a+b>c && a+c>b && b+c>a){
            double p = (a+b+c)/2;
            cout<<int64_t(a+b+c)<<" "<<int64_t(sqrt(p*(p-a)*(p-b)*(p-c))+0.5)<<"\n";
        }
        else {
            cout<<"Not a triangle.\n";
        }
    }

}
