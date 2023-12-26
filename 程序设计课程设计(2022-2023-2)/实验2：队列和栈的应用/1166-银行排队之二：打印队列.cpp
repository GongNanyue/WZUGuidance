#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;


struct person {
    string idx;
    string vip;
    int cnt ;
    person(string idx,string vip,int cnt){
        this->idx = idx;
        this->vip = vip;
        this->cnt = cnt;
    }
};

int main() {
    vector<person> ps;
    string op;
    int cnt = 0;
    int vip = 0;
    while (cin >> op) {
        if (op == "QUIT") {
            cout << "GOOD BYE!" << endl;
            break;
        } else if (op == "IN") {
            ++cnt;
            string idx, state;
            cin >> idx >> state;
            ps.push_back(person(idx,state,cnt));
            cout << "IN:" << cnt << " " << idx << " " << state << " " << (cnt - 1) << endl;
        } else if (op == "LIST"){
            cout << "LIST:" << endl;
            for (int i = 0; i <ps.size(); ++i)
                cout << ps[i].cnt << " " << ps[i].idx << " " << ps[i].vip << " " << (ps[i].cnt - 1) << endl;
        }
    }

    return 0;
}