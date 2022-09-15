#include <bits/stdc++.h>

using namespace std;

double f(double x, double y) {
    if (x < 0)
        return x + y;
    else
        return f(x-1,x+y)+x/y;
}

int main() {
    int m;
    cin >> m;
    cout.setf(ios::fixed);
    cout.precision(2);
    while (m--) {
        double x, y;
        cin >> x >> y;
        cout << f(x,y) << endl;
    }
    return 0;
}
