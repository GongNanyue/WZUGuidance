#include <bits/stdc++.h>

using namespace std;

bool is_tri(int c, int a, int b) {
    return c * c == b * b + a * a;
}

int main() {
    int n,m;
    cin >> n >> m;
    int sum = 1;
    for(int i = 0;i < m;++i){
        sum *= n;
    }
    cout << sum << endl;
    return 0;
}
