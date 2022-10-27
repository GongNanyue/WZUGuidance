#include <bits/stdc++.h>
using namespace std;

int strrindex(char s[], char t[]) {
  int slen = strlen(s), tlen = strlen(t);
  char *sp = s+slen-tlen;
  while(sp>=s){
    int i;
    for(i = 0; i<tlen; ++i){
      if(*(t+i) != *(sp+i))
        break;
    }
    if(i == tlen){
      return sp-s;
    }
    --sp;
  }
  return -1;
}
char s[1010],t[1010];
int main() {
  gets(s);
  gets(t);
  printf("%d\n", strrindex(s,t));
  return 0;
}
