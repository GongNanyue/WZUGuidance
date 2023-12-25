#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    if (pow(a%10,3) + pow(int(a/10)%10,3) + pow(int(a/100),3) == a) cout<<"Yes\n";
    else cout<<"No\n";
}
