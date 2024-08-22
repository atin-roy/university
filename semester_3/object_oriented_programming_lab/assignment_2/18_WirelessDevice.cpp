#include <cmath>
#include <cstdlib>
#include <ctime>
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

  double getX() const { return x; }
  double getY() const { return y; }
  double getZ() const { return z; }

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

class WirelessDevice {
private:
  Point location;
  int id;
  double transmissionRange;

public:
  WirelessDevice() = default;

  WirelessDevice(int id, double x, double y, double z, int transmissionRange)
      : id(id), location(x, y, z), transmissionRange(transmissionRange) {}

  Point getLocation() const { return this->location; }

  int getId() const { return id; }

  double getTransmissionRange() const { return transmissionRange; }

  void setLocation(Point &location) { this->location = location; }

  void setLocation(double x, double y, double z) { location = Point(x, y, z); }

  void setId(int id) { this->id = id; }

  void setTransmissionRange(double transmissionRange) {
    this->transmissionRange = transmissionRange;
  }

  void setRandomLocation() {
    setLocation(rand() % 101, rand() % 101, rand() % 101);
  }

  void setRandomTransmissionRange() { setTransmissionRange(rand() % 100 + 1); }

  void setRandomId() { setId(rand() % 1000 + 1); }

  bool isNeighbor(const WirelessDevice &other) const {
    return this->location.distance(other.location) <= transmissionRange;
  }

  void moveDevice() { setRandomLocation(); }

  void printDetails() {
    cout << "Device ID: " << id << ", " << "Location: ";
    location.display();
    cout << ", " << "Transmission Range: " << transmissionRange << endl;
  }
};

void findNeighbors(WirelessDevice devices[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "The neighbors of Device " << devices[i].getId()
         << " are : " << endl;
    for (int j = 0; j < size; j++) {
      if (i == j)
        continue;
      else if (devices[i].isNeighbor(devices[j])) {
        devices[j].printDetails();
      }
    }

    cout << endl;
  }
}

int main() {
  srand(time(0));
  WirelessDevice devices[10];

  for (int i = 0; i < 10; i++) {
    devices[i].setRandomId();
    devices[i].setRandomLocation();
    devices[i].setRandomTransmissionRange();
  }

  findNeighbors(devices, 10);

  for (int i = 0; i < 10; i++) {
    devices[i].moveDevice();
  }

  cout << "\nAfter moving the devices, new neighbors are: \n" << endl;
  findNeighbors(devices, 10);

  return 0;
}
