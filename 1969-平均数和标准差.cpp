#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    vector<int> v;
    int m;
    cin >> m;
    string str;
    getline(cin, str);
    int val = 0;
    double sum = 0.0;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == ' ') {
        sum += val;
        if(sum)v.push_back(val);
        val = 0;
      } else {
        val = val * 10 + str[i] - '0';
      }
    }
    sum += val;
    v.push_back(val);
    double avg = sum / m;
    double deviation = 0;
    for (int i = 0; i < m; ++i) {
      deviation+= pow((v[i]-avg),2);
    }
    deviation= sqrt(deviation/m);
    printf("%.3lf %.3lf\n", avg,deviation);
  }
  return 0;
}
