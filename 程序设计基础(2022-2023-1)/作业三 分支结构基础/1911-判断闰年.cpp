#include <bits/stdc++.h>

using namespace std;


int main() {
    int x;
    cin >> x;
    if(x %400==0){
        cout << "Y\n"; 
    } else if(x%100 ==0){
        cout << "N\n";
    }else if( x %4 == 0){
        cout << "Y\n";
    }else {
        cout << "N\n";
    }
    return 0;
}
