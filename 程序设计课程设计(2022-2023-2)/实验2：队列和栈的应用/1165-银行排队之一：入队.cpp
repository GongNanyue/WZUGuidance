#include <bits/stdc++.h>
using namespace std;


struct person {
    int idx;
    bool vip;
};

int main() {
    string op;
    int cnt = 0;
    int vip = 0;
    while (cin >> op) {
        if (op == "QUIT") {
            cout << "GOOD BYE!" << endl;
            break;
        }

        else if (op == "IN") {
            ++cnt;
            string idx, state;
            cin >> idx >> state;
            cout << "IN:" << cnt << " " << idx << " " << state <<  " " << (cnt - 1) << endl;
        }
    }

    return 0;
}