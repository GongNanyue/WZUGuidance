#include <bits/stdc++.h>
using namespace std;
string str;
vector<string> v;
vector<pair<string, int> > m;

string upperMy(const string &s) {
  string res;
  for(int i = 0; i<s.size(); ++i){
    res.push_back(toupper(s[i]));
  }
  return res;
}

void calS() {
  str.push_back(' ');
  int i = 0, j = 0;
  while(str[i] == ' ')++i;
  j = i;
  while(j != str.size()){
    while(j != str.size() && isalpha(str[j]))++j;
    v.push_back(upperMy(str.substr(i, j-i)));
    while(isspace(str[j]))++j;
    i = j;
  }
}

void calV() {
  calS();
  sort(v.begin(), v.end());
  int i = 0, j = 0;
  while(j != v.size()){
    while(j != v.size() && v[i] == v[j])++j;
    m.push_back({v[i], j-i});
    i = j;
  }
}

void display() {
  calV();
  cout << m.size() << endl;
  for(int i = 0 ;i < m.size();++i){
    cout<<m[i].first<<" "<<m[i].second<<endl;
  }
  str.clear();
  v.clear();
  m.clear();
}

int main() {
  int n;
  cin>>n;
  getchar();
  char c;
  while(n != 0){
    c = getchar();
    if(c == '\n'){
      str.push_back(' ');

      continue;
    }
    if(c == '#'){
      --n;
      display();
      getchar();
    }
    if(c!='#')str.push_back(c);
  }

  return 0;
}
