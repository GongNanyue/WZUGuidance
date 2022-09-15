#include <bits/stdc++.h>

using namespace std;


int main() {
    char c;
    cin >> c;
    if('A'<=c&&c<='Z'||'a'<=c&&c<='z'){
            cout <<"1" << endl;
    } else if('0'<= c&&c<= '9'){
        cout << "0" << endl;
    } else{
        cout << "-1" << endl;
    }
    return 0;
}
