#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <cstdio>
using namespace std;

char buf[2000010];

void read(string &s) {
    scanf("%s", buf);
    s = string(buf);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    string s;
    read(s);
    int i = 0, j = 0;
    set<string> st;
    while (i < s.size()) {
        while (j < s.size() && isdigit(s[j])) j++;
        st.insert(s.substr(i, j - i));
        i = j;
        while (i < s.size() && !isdigit(s[i])) i++;
        j = i;
    }
    int n;
    cin >> n;
    while (n--) {
        string t;
        read(t) ;
        if (st.count(t)) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
