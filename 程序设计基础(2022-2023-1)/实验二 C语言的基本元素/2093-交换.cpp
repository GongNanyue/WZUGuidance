#include <bits/stdc++.h>

using namespace std;

template<typename T>
void myswap(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

int main() {
    int a, b;
    cin >> a >> b;
    myswap(a, b);
    cout << a << " " << b << endl;
    return 0;
}
