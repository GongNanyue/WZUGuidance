#include <iostream>
#include <deque>
using namespace std;



struct comsumer {
    int cnt;
    string id, state;
};


int main() {
    string op;
    deque<comsumer> q;
    int inCnt = 0, outCnt = 0;
    while (true) {
        cin >> op;
        if (op == "QUIT") {
            cout << "GOOD BYE!" << endl;
            break;
        } else if (op == "IN") {
            comsumer c;
            cin >> c.id >> c.state;
            c.cnt = ++inCnt;
            cout << "IN:" << inCnt << " " << c.id << " " << c.state << " " << q.size() << endl;
            q.push_back(c);
        } else if (op == "OUT") {
            if (q.empty()) {
                cout << "FAILED:" << endl;
                continue;
            }
            cout << "OUT:" << ++outCnt << " " << q.front().id << " " << q.front().state << endl;
            q.pop_front();
        } else if (op == "LIST") {
            cout << "LIST:" << endl;
            for (int i = 0; i < q.size(); ++i)
                cout << q[i].cnt << " " << q[i].id << " " << q[i].state << endl;
        }
    }


    return 0;
}