#include <cstdio>
#include <string>
using namespace std;
string s;
int pos;
long long cntAnd, cntOr;
 
int parseExpression(bool eval);
int parseAnd(bool eval);
int parsePrimary(bool eval);
 
int parsePrimary(bool eval) {
    int res = 0;
    if(s[pos]=='('){
        pos++; 
        res = parseExpression(eval);
        pos++;
    } else {
        res = s[pos]-'0';
        pos++;
    }
    return res;
}
 
int parseAnd(bool eval) {
    int res = parsePrimary(eval);
    while(pos < s.size() && s[pos]=='&'){
        pos++;
        if(eval && res==0) {
            cntAnd++;
            int dummy = parsePrimary(false);
            res = 0;
        } else {
            int right = parsePrimary(eval);
            if(eval) res = res & right;
            else res = 0;
        }
    }
    return res;
}
 
int parseExpression(bool eval) {
    int res = parseAnd(eval);
    while(pos < s.size() && s[pos]=='|'){
        pos++;
        if(eval && res==1) {
            cntOr++;
            int dummy = parseAnd(false);
            res = 1;
        } else {
            int right = parseAnd(eval);
            if(eval) res = res | right;
            else res = 0;
        }
    }
    return res;
}
 
int main(){
    char ch;
    while((ch = getchar())!=EOF){
        if(ch=='\n') break;
        s.push_back(ch);
    }
    pos = 0;
    cntAnd = cntOr = 0;
    int result = parseExpression(true);
    printf("%d\n%lld %lld", result, cntAnd, cntOr);
    return 0;
}
