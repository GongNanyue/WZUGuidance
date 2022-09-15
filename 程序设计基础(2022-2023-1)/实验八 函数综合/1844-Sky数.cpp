#include <bits/stdc++.h>

using namespace std;
int j12[10];
int j16[10];
int j10[10];

void init() {
    for (int i = 0; i < 10; ++i) {
        j10[i] = 0;
        j12[i] = 0;
        j16[i] = 0;
    }
}

void _16trans(int x) {
    int i = 0;
    while (x) {
        j16[i++] = x % 16;
        x /= 16;
    }
    j16[i] = -1;
}

void _12trans(int x) {
    int i = 0;
    while (x) {
        j12[i++] = x % 12;
        x /= 12;
    }
    j12[i] = -1;
}

void _10trans(int x) {
    int i = 0;
    while (x) {
        j10[i++] = x % 10;
        x /= 10;
    }
    j10[i] = -1;
}

bool check(int x) {
    init();
    _10trans(x);
    _12trans(x);
    _16trans(x);
    int sum10 = 0, sum12 = 0, sum16 = 0;
    for (int i = 0; j10[i] != -1; ++i) {
        sum10 += j10[i];
    }
    for (int i = 0; j12[i] != -1; ++i) {
        sum12 += j12[i];
    }
    for (int i = 0; j16[i] != -1; ++i) {
        sum16 += j16[i];
    }
    if(sum10==sum12&&sum12==sum16)
        return true;
    else
        return false;
}

int main() {
    int m;
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        if(check(a)){
            cout << a << " is a Sky Number." << endl;
        }else {
            cout << a << " is not a Sky Number." << endl;
        }
    }
    return 0;
}
