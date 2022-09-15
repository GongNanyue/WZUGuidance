#include <bits/stdc++.h>

using namespace std;
int sqr(int x){
    return x*x;
}

int main() {
    for (int i = 1; i < 100; ++i) {
        if(1<=i&&i < 10){
            if(i==(sqr(i)%10))cout << i << " ";
        } else{
            if(i == (sqr(i)%100))cout << i << " ";
        }
    }


    cout << endl;
    return 0;
}
