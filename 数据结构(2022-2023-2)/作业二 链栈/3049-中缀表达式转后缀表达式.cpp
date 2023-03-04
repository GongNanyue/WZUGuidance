#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;
stack<int> nums;
stack<char> ops;
string res;

bool isOp(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/')
    return true;
  return false;
}

void out() {
  res.push_back(ops.top());
  ops.pop();
}

int main() {

  mp['('] = 0;
  mp['+'] = 1;
  mp['-'] = 1;
  mp['*'] = 2;
  mp['/'] = 2;
  for (char c = std::getchar(); c != EOF && c != '\n'; c = std::getchar()) {
    if (c == '(')
      ops.push('(');
    else if (c == ')') {
      while (ops.top() != '(')
        out();
      ops.pop();// pop '('
    } else if (std::isdigit(c)) {
      res.push_back(c);
    } else if (isOp(c)) {
      while (!ops.empty() && mp[c] <= mp[ops.top()]) {
        out();
      }
      ops.push(c);
    }
  }
  while (!ops.empty())
    out();
  for (int i = 0; i < res.size(); ++i)
    cout << res[i] << (i == res.size() - 1 ? "\n" : " ");
  return 0;
}

