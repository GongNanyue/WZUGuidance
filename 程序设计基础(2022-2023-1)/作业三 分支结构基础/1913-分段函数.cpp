#include <bits/stdc++.h>

using namespace std;


int main() {
    double x;
    cin >> x;
    cout.setf(ios::fixed);
    cout.precision(3);
    if(-5<=x&&x<0){
        cout << 8.0/(x*x+x+1) << endl;
    }else if(0 <= x&&x <5){
        cout << 7.0/(x*x+x+1) << endl;
    }else if(5<=x && x<= 10){
        cout << 2.0/(x+8.0) << endl;
    } else{
        cout << "0.000" << endl;
    }
    return 0;
}
