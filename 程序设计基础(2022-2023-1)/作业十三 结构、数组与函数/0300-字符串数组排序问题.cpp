#include <bits/stdc++.h>
using namespace std;

string a[1000];

bool inc(const string &s1, const string &s2) {
  __gnu_cxx::__normal_iterator<const char *, basic_string<char> > it1 = s1.begin();
  __gnu_cxx::__normal_iterator<const char *, basic_string<char> > it2 = s2.begin();
  while(it1 != s1.end() && it2 != s2.end()){
    if(!isalpha(*it1) ){
      ++it1;
      continue;
    }
    if(!isalpha(*it2) ){
      ++it2;
      continue;
    }
    if(*it1 == *it2){
      ++it1;
      ++it2;
      continue;
    }
    return *it1<*it2;
  }
  if(it1 == s1.end() && it2 != s2.end()){
    return true;
  }else{
    return false;
  }
}

bool ldec(const string &s1, const string &s2) {

  __gnu_cxx::__normal_iterator<const char *, basic_string<char> > it1 = s1.begin();
  __gnu_cxx::__normal_iterator<const char *, basic_string<char> > it2 = s2.begin();
  while(it1 != s1.end() && it2 != s2.end()){
    if(!isalpha(*it1) ){
      ++it1;
      continue;
    }
    if(!isalpha(*it2) ){
      ++it2;
      continue;
    }
    if(*it1 == *it2){
      ++it1;
      ++it2;
      continue;
    }
    return *it1>*it2;
  }
  if(it1 != s1.end() && it2 == s2.end()){
    return true;
  }else{
    return false;
  }
}

bool ncinc(const string &s1, const string &s2) {
  __gnu_cxx::__normal_iterator<const char *, basic_string<char> > it1 = s1.begin();
  __gnu_cxx::__normal_iterator<const char *, basic_string<char> > it2 = s2.begin();
  while(it1 != s1.end() && it2 != s2.end()){
    if(!isalpha(*it1)){
      ++it1;
      continue;
    }
    if(!isalpha(*it2)){
      ++it2;
      continue;
    }
    if(toupper(*it1) == toupper(*it2)){
      ++it1;
      ++it2;
      continue;
    }
    return toupper(*it1)<toupper(*it2);
  }
  if(it1 == s1.end() && it2 != s2.end()){
    return true;
  }else{
    return false;
  }
}

bool ncdec(const string &s1, const string &s2) {
  __gnu_cxx::__normal_iterator<const char *, basic_string<char> > it1 = s1.begin();
  __gnu_cxx::__normal_iterator<const char *, basic_string<char> > it2 = s2.begin();
  while(it1 != s1.end() && it2 != s2.end()){
    if(!isalpha(*it1)){
      ++it1;
      continue;
    }
    if(!isalpha(*it2)){
      ++it2;
      continue;
    }
    if(*it1 == *it2){
      ++it1;
      ++it2;
      continue;
    }
    return toupper(*it1)>toupper(*it2);
  }
  if(it1 != s1.end() && it2 == s2.end()){
    return true;
  }else{
    return false;
  }
}

int main() {
  string op;
  cin>>op;
  int n;
  cin>>n;
  getchar();
  for(int i = 0; i<n; ++i){
    getline(cin, a[i]);
  }
  if(op == "inc"){
    sort(a, a+n, inc);
  }else if(op == "dec"){
    sort(a, a+n, ldec);
  }else if(op == "ncinc"){
    sort(a, a+n, ncinc);
  }else if(op == "ncdec"){
    sort(a, a+n, ncdec);
  }
  for(int i = 0; i<n; ++i){
    cout<<a[i]<<endl;
  }

  return 0;
}
