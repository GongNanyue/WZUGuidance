#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {

    int sum = 0;
    while (cin >> n >> m && n && m) {
        for (int i = n; i <= m; ++i) {
            bool flag = true;
            int x = i;
            while (x) {
                if (x % 10 == 4 || x % 10 == 2 && x / 10 % 10 == 6) {
                    flag = false;
                    break;
                }
                x /= 10;
            }
            if(flag)sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
