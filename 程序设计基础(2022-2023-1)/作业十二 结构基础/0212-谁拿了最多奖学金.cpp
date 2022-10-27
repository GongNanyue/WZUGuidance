#include <bits/stdc++.h>
using namespace std;

const int N = 110;
struct st {
  char id[30];
  int s1, s2;
  bool b1, b2;
  int e;
  int sum;

  void cal() {
    if(s1>80 && e>=1)sum += 8000;
    if(s1>85 && s2>80)sum += 4000;
    if(s1>90)sum += 2000;
    if(s1>85 && b2)sum += 1000;
    if(s2>80 && b1)sum += 850;
  }

  bool operator>(const st &s) const {
    return this->sum>s.sum;
  }
};
st a[N];

int main() {
  int n;
  cin>>n;
  getchar();
  for(int i = 0; i<n; ++i){
    cin>>a[i].id>>a[i].s1>>a[i].s2;
    char c1, c2;
    getchar();
    scanf("%c %c", &c1, &c2);
    if(c1 == 'Y')
      a[i].b1 = true;
    else
      a[i].b1 = false;
    if(c2 == 'Y')
      a[i].b2 = true;
    else
      a[i].b2 = false;
    cin>>a[i].e;
    a[i].sum = 0;
    a[i].cal();
  }
  stable_sort(a,a+n,greater<st>());
  cout << a[0].id << endl << a[0].sum << endl;
  int sum = 0;
  for(int i = 0;i < n;++i){
    sum += a[i].sum;
  }
  cout << sum << endl;
  return 0;
}
