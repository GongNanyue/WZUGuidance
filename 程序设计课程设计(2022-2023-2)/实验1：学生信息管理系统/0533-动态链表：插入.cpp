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

void insert(Student &s) {
  cin >> s.id >> s.name >> s.gender >> s.chinese >> s.math >> s.english;
}

int main() {
  vector<Student> v;
  while (true) {
    string mode;
    cin >> mode;
    if (mode == "Exit" || mode == "Quit") {
      cout << "Good bye!" << endl;
      break;
    } else if (mode == "Insert") {
      Student s;
      insert(s);
      cout.setf(ios::fixed);
      cout.precision(1);
      cout << "Insert:" << endl << s.id << " " << s.name << " " << s.gender << " " <<s.chinese << " " << s.math << " "
           << s.english << endl;
    }

  }
  return 0;
}
