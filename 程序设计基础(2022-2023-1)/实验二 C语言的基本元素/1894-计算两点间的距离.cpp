#include <bits/stdc++.h>

using namespace std;


int main() {

    double x1, x2, y1, y2;
    cin >> x1 >>y1  >> x2 >> y2;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << sqrt(pow(x1-x2,2)+ pow(y1-y2,2))<<endl;
    return 0;
}
