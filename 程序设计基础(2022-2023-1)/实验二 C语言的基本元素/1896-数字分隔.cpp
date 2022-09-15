#include <bits/stdc++.h>

using namespace std;


int main() {
    string str;

    getline(cin,str );
    for (int i = 0; i < 5; ++i) {
        cout << str[i];
        if(i !=4) cout << "---";
    }
    cout << endl;
    return 0;
}
