#include <bits/stdc++.h>

using namespace std;
int digit[10];

void init() {
    for (int i = 0; i < 10; ++i)digit[i] = -1;
}

void getdigit(int a) {
    init();
    int k = 0;
    while (a) {
        digit[k++] = a % 10;
        a /= 10;
    }
}

bool check(int a) {
    getdigit(a);
    int sum = 0;
    for (int i = 0; digit[i] != -1; ++i) {
        sum += digit[i];
    }
    return (a % sum == 0);
}

int main() {
    int n;
    cin >> n;

    for (int i = 10; i <= n; ++i) {
        if (check(i))cout << i << endl;
    }
    return 0;
}
