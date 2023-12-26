#include <bits/stdc++.h>
using namespace std;

struct Student {
  string id;
  string name;
  char gender;
  double chinese;
  double math;
  double english;
};
vector<Student> v;

int main() {
  cout.setf(ios::fixed);
  cout.precision(1);
  while (true) {
    string mode;
    cin >> mode;
    if (mode == "Exit" || mode == "Quit") {
      cout << "Good bye!" << endl;
      break;
    } else if (mode == "Insert") {
      Student s;
      cin >> s.id >> s.name >> s.gender >> s.chinese >> s.math >> s.english;
      v.push_back(s);
      cout << "Insert:" << endl << s.id << " " << s.name << " " << s.gender << " " << s.chinese << " " << s.math << " "
           << s.english << endl;
    } else if (mode == "List") {
      cout << "List:" << endl;
      for (int i = 0; i < v.size(); ++i) {
        cout << v[i].id << " " << v[i].name << " " << v[i].gender << " " << v[i].chinese << " " << v[i].math << " "
             << v[i].english << endl;
      }
    } else if (mode == "Change") {
      cout << "Change:" << endl;
      string id, newName;
      char newGender;
      double newChinese, newMath, newEnglish;
      cin >> id >> newName >> newGender >> newChinese >> newMath >> newEnglish;
      int i = 0;
      for (; i < v.size(); ++i) {
        if (v[i].id == id)break;
      }
      if (i == v.size())
        cout << "Failed" << endl;
      else {
        v[i].name = newName;
        v[i].gender = newGender;
        v[i].chinese = newChinese;
        v[i].math = newMath;
        v[i].english = newEnglish;
        cout << v[i].id << " " << v[i].name << " " << v[i].gender << " " << v[i].chinese << " " << v[i].math << " "
             << v[i].english << endl;
      }

    } else if (mode == "Find") {
      cout << "Find:" << endl;
      string id;
      cin >> id;
      int i = 0;
      for (; i < v.size(); ++i) {
        if (v[i].id == id)break;
      }
      if (i == v.size())
        cout << "Failed" << endl;
      else
        cout << v[i].id << " " << v[i].name << " " << v[i].gender << " " << v[i].chinese << " " << v[i].math << " "
             << v[i].english << endl;
    }
  }
  return 0;
}