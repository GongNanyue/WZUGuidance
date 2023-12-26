#include <iostream>
#include <deque>
using namespace std;


int main() {
    string op;
    deque<string> backQ, forwardQ;


    while (true) {
        cin >> op;
        if (op == "QUIT")break;
        else if (op == "VISIT") {
            string web;
            cin >> web;
            forwardQ.clear();
            backQ.push_back(web);
            cout << backQ.back() << endl;
        } else if (op == "BACK") {
            if (backQ.empty()) {
                cout << "Ignored" << endl;
                continue;
            }
            string top = backQ.back();
            backQ.pop_back();
            forwardQ.push_back(top);
            if (backQ.empty()) {
                string top = forwardQ.back();
                forwardQ.pop_back();
                backQ.push_back(top);
                cout << "Ignored" << endl;
                continue;
            }
            cout << backQ.back() << endl;
        } else if (op == "FORWARD") {
            if (forwardQ.empty()) {
                cout << "Ignored" << endl;
                continue;
            }
            string top = forwardQ.back();
            forwardQ.pop_back();
            backQ.push_back(top);
            cout << backQ.back() << endl;
        }
    }


    return 0;
}