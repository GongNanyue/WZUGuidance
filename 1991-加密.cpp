#include <bits/stdc++.h>

using namespace std;

int main() {
  string s,t;
  while (cin >> s >> t){
    int idx = 0;
    for (int i = 0; i < t.size(); ++i) {
      if(s[idx]==t[i]){
        idx++;
      }
    }
    if(idx == s.size()){
      printf("Yes\n");
    } else{
      printf("No\n");
    }
  }
  return 0;
}
