#include <bits/stdc++.h>

using namespace std;
const double Pi = 3.1415926;

int main() {
    int a,b;
    cin >> a >> b;
    if(a > b){
        cout << ">" << endl;
    } else if( a== b){
        cout << "=" << endl;
    }else {
        cout  << "<" << endl;
    }

    return 0;
}
