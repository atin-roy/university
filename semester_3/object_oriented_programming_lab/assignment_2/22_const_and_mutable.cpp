#include <iostream>
#include <string>

class Demo {
private:
  std::string name;
  mutable int accessCount;

public:
  Demo(std::string name) : name(name), accessCount(0) {}

  std::string getName() const {
    accessCount++;
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
