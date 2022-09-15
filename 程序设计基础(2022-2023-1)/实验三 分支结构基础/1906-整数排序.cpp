#include <bits/stdc++.h>

using namespace std;
int v[3];

int main() {
    for (int i = 0; i < 3; ++i) {
        cin >> v[i];
    }
    sort(v, v + 3);
    for (int i = 0; i < 3; ++i) {
        cout << v[i];
        if (i != 2)cout << " ";
    }
cout << endl;
    return 0;
}
