/*
Write a class that represents a class of wireless device. A device has a
location (point object may be used), a fixed unique id, and a fixed circular
transmission range. Write suitable constructors and member functions for this
class. Instantiates 10 such devices. Choose location (coordinates) and
transmission range of the devices randomly. Now, for each of these devices, find
the neighbor devices (i.e. devices that belong to the transmission range).
Suppose, all of these devices have moved to a new location (randomly chosen).
Find out the new set of neighbors for each of these devices.
*/
/*
- use Point for location
- id (int)
- range

- constructors

- 10 device
- choose locations and range randomly (mem funcs 2)
- for each device find neighbor (range <= this.range) [mem func 3]
- move the devices to new locations [mem func 4]
- find new neighbors [mem func 3]
*/
#include "16_Point.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class WirelessDevice {
private:
  Point location;
  int id;
  double transmissionRange;

public:
  // constructors
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

  // initialize all objects
  for (int i = 0; i < 10; i++) {
    devices[i].setRandomId();
    devices[i].setRandomLocation();
    devices[i].setRandomTransmissionRange();
  }

  // find neighbours
  findNeighbors(devices, 10);

  // move the devices
  for (int i = 0; i < 10; i++) {
    devices[i].moveDevice();
  }

  // re-find the neighbors
  cout << "\nAfter moving the devices, new neighbors are: \n" << endl;
  findNeighbors(devices, 10);

  return 0;
}