#include <bits/stdc++.h>

using namespace std;


int main() {
    int p;
    cin >> p;
    if (p < 0 || p > 100) {
        cout << "Score is error!" << endl;
    } else if (90 <= p && p <= 100) {
        cout << "A" << endl;
    } else if (80 <= p && p <= 89) {
        cout << "B" << endl;
    } else if (70 <= p && p <= 79) {
        cout << "C" << endl;
    } else if (60 <= p && p <= 69) {
        cout << "D" << endl;
    }else {
        cout << "E" << endl;
    }
    return 0;
}
