#include <iostream>
#include <deque>
using namespace std;


struct comsumer {
    int cnt;
    string id, state;
};


int main() {
    string op;
    deque<comsumer> qOr;
    deque<comsumer> qVip;
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

            if (c.state == "Ordinary") {
                cout << "IN:" << inCnt << " " << c.id << " " << c.state << " " << qOr.size() + qVip.size() << endl;
                qOr.push_back(c);
            } else if (c.state == "VIP") {
                cout << "IN:" << inCnt << " " << c.id << " " << c.state << " " << qVip.size() << endl;
                qVip.push_back(c);
            }

        } else if (op == "OUT") {
            if (qVip.empty() && qOr.empty()) {
                cout << "FAILED:" << endl;
                continue;
            }
            if (!qVip.empty()) {
                cout << "OUT:" << qVip.front().cnt << " " << qVip.front().id << " " << qVip.front().state << endl;
                qVip.pop_front();
            } else {
                cout << "OUT:" << qOr.front().cnt << " " << qOr.front().id << " " << qOr.front().state << endl;
                qOr.pop_front();
            }
        } else if (op == "LIST") {
            cout << "LIST:" << endl;
            for (int i = 0; i < qVip.size(); ++i)
                cout << qVip[i].cnt << " " << qVip[i].id << " " << qVip[i].state << endl;
            for (int i = 0; i < qOr.size(); ++i)
                cout << qOr[i].cnt << " " << qOr[i].id << " " << qOr[i].state << endl;
        }
    }


    return 0;
}