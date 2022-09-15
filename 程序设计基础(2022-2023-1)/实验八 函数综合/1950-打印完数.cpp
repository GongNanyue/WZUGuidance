#include <bits/stdc++.h>

using namespace std;


int factor[100];

void init() {
    for (int i = 0; i < 100; ++i) {
        factor[i] = 0;
    }
}

void fact(int a) {
    int k = 0;
    init();
    for (int i = 1; i < a; ++i) {
        if (a % i == 0)factor[k++] = i;
    }
}

int sum(int a) {
    fact(a);
    int sum = 0;
    for (int i = 0; factor[i] != 0; ++i) {
        sum += factor[i];

    }
    return sum;
}

bool check(int a) {
    return sum(a) == a;
}

int main() {
    for (int i = 1; i <= 1000; ++i) {
        if (check(i)) {
            cout << i << " its factors are ";
            for (int j = 0; factor[j] != 0; ++j) {
                cout << factor[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
