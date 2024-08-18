/*
Write a simple class that represents a class of geometrical points each of which
has three coordinates. The class should have appropriate constructor(s). Also
add a member function distance() that calculates Euclidian distance between two
points. Now create two points, find the distance between them and print it.
*/
#include <cmath>
#include <iostream>

using namespace std;

class Point {
private:
  double x, y, z;

public:
  Point() = default;

  Point(double x, double y = 0, double z = 0) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  // getters
  double getX() const { return x; }
  double getY() const { return y; }
  double getZ() const { return z; }

  // setters
  void setX(double x) { this->x = x; }
  void setY(double y) { this->y = y; }
  void setZ(double z) { this->z = z; }

  double distance(const Point &other) const {
    double x_dis = other.x - x;
    double y_dis = other.y - y;
    double z_dis = other.z - z;

    double distance = sqrt(x_dis * x_dis + y_dis * y_dis + z_dis * z_dis);
    return distance;
  }

  void display() { cout << "(" << x << "," << y << "," << z << ")"; }
};

// int main() {
//   Point P(5, 2, 0);
//   Point Q(0, 0, 0);

//   std::cout << "Distance between P and Q: " << P.distance(Q) << std::endl;
//   return 0;
// }