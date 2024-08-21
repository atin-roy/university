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
  // Default constructor
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

  // Parameterized constructor
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
    cgpa = (cgpa / 500) * 10; // Assuming CGPA is based on 500 marks (5 subjects
                              // * 100 max per subject)
  }
  // Setters
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

  // Getters
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
  // Method to display the GradeCard details
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

vector<GradeCard> createGradeCards(int n) {
  vector<GradeCard> cards;
  string depts[] = {"Information Technology", "Power Engineering",
                    "Electrical Engineering", "Computer Science",
                    "Civil Engineering",      "Construction Engineering"};

  for (int i = 0; i < n; i++) {
    int marks[5];
    for (int j = 0; j < 5; j++) {
      marks[j] = rand() % 100 + 1; // Generates marks between 1 and 100
    }

    cards.emplace_back(depts[rand() % 6], randomName(), i + 1, 3, marks);
  }

  return cards; // Return the vector of GradeCard objects
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
  srand(time(0)); // Seed for random number generation

  // Create 60 GradeCard objects
  vector<GradeCard> cards = createGradeCards(60);

  // Find the GradeCard with the highest CGPA
  GradeCard &topStudent = findHighestCGPA(cards);

  // Display the details of the student with the highest CGPA
  cout << "Student with the highest CGPA:\n";
  cout << "Name: " << topStudent.getStudentName() << endl;
  cout << "Roll Number: " << topStudent.getRoll() << endl;
  cout << "CGPA: " << topStudent.getCGPA() << endl;

  return 0;
}
