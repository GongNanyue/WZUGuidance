/*
！！！！注意！！！！
这一个代码不能通过编译，因为使用了stl
而且测试点的答案好像有错误
题目中说的标准差是全体标准差，不是样本标准差
https://www.shuxuele.com/data/standard-deviation-formulas.html
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v;
  int n;
  scanf("%d\n", &n);
  while (n--) {
    int i = 0;
    string str;
    getline(cin, str);
    str += ' ';
    int val = 0;
    for (i = 0; i < str.size(); ++i) {
      if (isdigit(str[i])) {
        val = val * 10 + str[i] - '0';
      } else {
        v.push_back(val);
        val = 0;
      }
    }
    double avg = 0.0, deviation = 0.0;
    for (auto it = v.begin(); it != v.end(); ++it) {
      avg += *it;
    }
    avg = avg / v.size();
    for (auto it = v.begin(); it != v.end(); ++it) {
      deviation+= pow((*it)-avg,2);
    }
    deviation = sqrt(deviation / v.size());
    printf("%.3lf %.3lf\n", avg, deviation);
    v.clear();
  }
  return 0;
}
