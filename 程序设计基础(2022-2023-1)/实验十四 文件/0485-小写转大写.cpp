#include <bits/stdc++.h>

using namespace std;
char s[1000];

int main() {
  gets(s);
  for(char *p = s; *p != '\0'; ++p){
    if('a'<=*p && *p<='z'){
      *p -= ' ';
    }
  }
  puts(s);
  return 0;
}
