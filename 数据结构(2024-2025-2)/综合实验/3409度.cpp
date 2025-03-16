#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int outdeg[1001] = {0};
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            outdeg[x]++;
        }
    }
    int k;
    cin >> k;
    cout << outdeg[k];
    return 0;
}
