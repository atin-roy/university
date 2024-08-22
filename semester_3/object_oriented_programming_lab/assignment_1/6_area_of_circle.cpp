#include <iostream>
using namespace std;

int main() {
  const double PI = 3.141592653589793;
  double radius;

  cout << "Enter the radius of the circle: ";
  cin >> radius;

  double area = PI * radius * radius;

  cout << "The area of the circle with radius " << radius << " is " << area
       << endl;

  return 0;
}
