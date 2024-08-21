#include <iostream>
#include <string>

class Demo {
private:
  std::string name;
  mutable int accessCount; // Mutable data member

public:
  // Constructor
  Demo(std::string name) : name(name), accessCount(0) {}

  // Constant member function that returns the name
  std::string getName() const {
    accessCount++; // Allowed because accessCount is mutable
    return name;
  }

  void setName(const std::string &newName) { name = newName; }

  int getAccessCount() const { return accessCount; }

  void display() const {
    std::cout << "Name: " << name << ", Access Count: " << accessCount
              << std::endl;
  }
};

int main() {
  Demo obj("InitialName");

  std::cout << "Name: " << obj.getName() << std::endl;
  std::cout << "Access Count: " << obj.getAccessCount() << std::endl;

  obj.display();

  obj.setName("NewName");

  obj.display();

  std::cout << "Name: " << obj.getName() << std::endl;
  std::cout << "Access Count: " << obj.getAccessCount() << std::endl;

  return 0;
}
