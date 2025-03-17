#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n + 1);
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        a[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int k;
    cin >> k;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j] == k){
                ans.push_back(i);
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
cout << "\n";
    return 0;
}
