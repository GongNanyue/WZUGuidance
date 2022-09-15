#include <bits/stdc++.h>

using namespace std;



bool is_primer(int x) {
    if (x < 2)return false;
    if (x == 2) return true;
    for (int i = 2; i < sqrt(x) + 1; ++i) {
        if (x % i == 0)return false;
    }
    return true;
}

int main() {
    int x;
    while ((cin >> x) && x) {
        int sum = 0;
        for (int i = x - 2; i >= 2; --i) {
           if(is_primer(i)&& is_primer(x-i))sum++;
        }
        cout << sum/2 << endl;
    }
    
    return 0;
}
