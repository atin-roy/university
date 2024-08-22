#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GradeCard {
private:
  string dept_name;
  string student_name;
  int roll;
  int sem;
  int marks[5];
  float cgpa;

public:
  GradeCard() {
    dept_name = "";
    student_name = "";
    roll = 0;
    sem = 0;
    for (int i = 0; i < 5; i++) {
      marks[i] = 0;
    }
    cgpa = 0.0;
  }

  GradeCard(string dept, string student, int r, int s, int m[5]) {
    dept_name = dept;
    student_name = student;
    roll = r;
    sem = s;
    cgpa = 0;
    for (int i = 0; i < 5; i++) {
      marks[i] = m[i];
      cgpa += marks[i];
    }
    cgpa = (cgpa / 500) * 10;
  }
  void setDeptName(string dept) { dept_name = dept; }

  void setStudentName(string student) { student_name = student; }

  void setRoll(int r) { roll = r; }

  void setSem(int s) { sem = s; }

  void setMarks(int m[5]) {
    for (int i = 0; i < 5; i++) {
      marks[i] = m[i];
    }
  }

  void setCGPA(float c) { cgpa = c; }

  string getDeptName() const { return dept_name; }

  string getStudentName() const { return student_name; }

  int getRoll() const { return roll; }

  int getSem() const { return sem; }

  void getMarks(int m[5]) const {
    for (int i = 0; i < 5; i++) {
      m[i] = marks[i];
    }
  }
  float getCGPA() const { return cgpa; }
  void display() const {
    cout << "Department: " << dept_name << endl;
    cout << "Student Name: " << student_name << endl;
    cout << "Roll Number: " << roll << endl;
    cout << "Semester: " << sem << endl;
    cout << "Marks: ";
    for (int i = 0; i < 5; i++) {
      cout << marks[i] << " ";
    }
    cout << endl;
    cout << "CGPA: " << cgpa << endl;
  }
};
string randomName() {
  string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string lower = "abcdefghijklmnopqrstuvwxyz";
  string name = "";

  int length = rand() % 10 + 1;
  name += capital[rand() % 26];
  for (int i = 1; i < length; i++) {
    name += lower[rand() % 26];
  }
  return name;
}

vector<GradeCard> createGradeCards(int n) {
  vector<GradeCard> cards;
  string depts[] = {"Information Technology", "Power Engineering",
                    "Electrical Engineering", "Computer Science",
                    "Civil Engineering",      "Construction Engineering"};

  for (int i = 0; i < n; i++) {
    int marks[5];
    for (int j = 0; j < 5; j++) {
      marks[j] = rand() % 100 + 1;
    }

    cards.emplace_back(depts[rand() % 6], randomName(), i + 1, 3, marks);
  }

  return cards;
}

GradeCard &findHighestCGPA(vector<GradeCard> &cards) {
  float highest = 0;
  int ind = -1;

  for (int i = 0; i < cards.size(); i++) {
    if (cards[i].getCGPA() > highest) {
      highest = cards[i].getCGPA();
      ind = i;
    }
  }

  return cards[ind];
}

int main() {
  srand(time(0));

  vector<GradeCard> cards = createGradeCards(60);

  GradeCard &topStudent = findHighestCGPA(cards);

  cout << "Student with the highest CGPA:\n";
  cout << "Name: " << topStudent.getStudentName() << endl;
  cout << "Roll Number: " << topStudent.getRoll() << endl;
  cout << "CGPA: " << topStudent.getCGPA() << endl;

  return 0;
}
