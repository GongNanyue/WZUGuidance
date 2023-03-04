#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;
stack<int> nums;
stack<char> ops;

bool isOp(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/')
    return true;
  return false;
}

void calculate() {
  char op = ops.top();
  ops.pop();
  int b = nums.top();
  nums.pop();
  int a = nums.top();
  nums.pop();
  if (op == '+')
    nums.push(a + b);
  else if (op == '-')
    nums.push(a - b);
  else if (op == '*')
    nums.push(a * b);
  else if (op == '/')
    nums.push(a / b);
}

int main() {
  mp['('] = 0;
  mp['+'] = 1;
  mp['-'] = 1;
  mp['*'] = 3;
  mp['/'] = 2;
  for (char c = std::getchar(); c != EOF && c != '\n'; c = std::getchar()) {
    if (c == '(')
      ops.push('(');
    else if (c == ')') {
      while (ops.top() != '(')
        calculate();
      ops.pop();// pop '('
    } else if (std::isdigit(c)) {
      nums.push(c - '0');
    } else if (isOp(c)) {
      while (!ops.empty()&& mp[c] < mp[ops.top()]) {
        calculate();
      }
      ops.push(c);
    }
  }
  while (!ops.empty())
    calculate();
  cout << nums.top() << endl;
  return 0;
}

