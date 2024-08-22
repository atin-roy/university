#include <cmath>
#include <iostream>
using namespace std;
class Rectangle {
private:
  double length;
  double breadth;

public:
  Rectangle() : length(0), breadth(0) {}

  Rectangle(double length, double breadth) {
    this->length = length;
    this->breadth = breadth;
  }

  double getLength() { return length; }

  double getBreadth() { return breadth; }

  void setLength(double length) { this->length = length; }

  void setBreadth(double breadth) { this->breadth = breadth; }

  double area() { return length * breadth; }
};

int main() {
  Rectangle r1(45, 23);
  Rectangle r2(42, 23);
  Rectangle r3(22, 35.555);
  Rectangle r4;

  cout << "Areas are: \n";
  cout << r1.area() << endl;
  cout << r2.area() << endl;
  cout << r3.area() << endl;
  cout << r4.area() << endl;

  return 0;
}
