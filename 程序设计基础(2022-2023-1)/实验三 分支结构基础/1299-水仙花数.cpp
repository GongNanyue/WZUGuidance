#include <bits/stdc++.h>

using namespace std;
const double Pi = 3.1415926;

int main() {
    int n;
    cin >> n;
    int a = n % 10, b = n / 10 % 10, c = n / 100;
    if (n == a * a * a + b * b * b + c * c * c) {
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }


    return 0;
}
