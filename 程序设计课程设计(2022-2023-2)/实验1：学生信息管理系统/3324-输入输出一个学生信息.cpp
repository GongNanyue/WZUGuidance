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
void insert(Student &s) {
  cin >> s.id >> s.name >> s.gender >> s.chinese >> s.math >> s.english;
  v.push_back(s);
}

int main() {
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
      std::printf("Insert:\n%s %s %c %.1f %.1f %.1f\n", s.id.c_str(),s.name.c_str(),s.gender,s.chinese,s.math,s.english);
    }

  }

  return 0;
}

3324-输入输出一个学生信息
