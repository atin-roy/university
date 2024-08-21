

#include <iostream>
#include <stdexcept>

class Vector {
private:
  int *data;
  int size;

public:
  // Constructor
  Vector(int size) : size(size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
      data[i] = 0; // Initialize all elements to 0
    }
  }

  // Copy Constructor
  Vector(const Vector &other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
      data[i] = other.data[i];
    }
  }

  // Destructor
  ~Vector() { delete[] data; }

  // Addition
  Vector operator+(const Vector &other) const {
    if (size != other.size) {
      throw std::invalid_argument(
          "Vectors must be of the same size for addition.");
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
      result.data[i] = data[i] + other.data[i];
    }
    return result;
  }

  // Subtraction
  Vector operator-(const Vector &other) const {
    if (size != other.size) {
      throw std::invalid_argument(
          "Vectors must be of the same size for subtraction.");
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
      result.data[i] = data[i] - other.data[i];
    }
    return result;
  }

  // Equality check
  bool operator==(const Vector &other) const {
    if (size != other.size) {
      return false;
    }
    for (int i = 0; i < size; ++i) {
      if (data[i] != other.data[i]) {
        return false;
      }
    }
    return true;
  }

  // Less than
  bool operator<(const Vector &other) const {
    if (size != other.size) {
      throw std::invalid_argument(
          "Vectors must be of the same size for comparison.");
    }
    for (int i = 0; i < size; ++i) {
      if (data[i] >= other.data[i]) {
        return false;
      }
    }
    return true;
  }

  // Greater than
  bool operator>(const Vector &other) const {
    if (size != other.size) {
      throw std::invalid_argument(
          "Vectors must be of the same size for comparison.");
    }
    for (int i = 0; i < size; ++i) {
      if (data[i] <= other.data[i]) {
        return false;
      }
    }
    return true;
  }

  // Access elements
  int &operator[](int index) {
    if (index >= size) {
      throw std::out_of_range("Index out of range.");
    }
    return data[index];
  }

  // Print vector
  void print() const {
    for (int i = 0; i < size; ++i) {
      std::cout << data[i] << " ";
    }
    std::cout << std::endl;
  }
};

int main() {
  Vector v1(3);
  Vector v2(3);

  // Set values
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

  v2[0] = 4;
  v2[1] = 5;
  v2[2] = 6;

  // Print vectors
  std::cout << "Vector v1: ";
  v1.print();
  std::cout << "Vector v2: ";
  v2.print();

  // Addition
  Vector v3 = v1 + v2;
  std::cout << "v1 + v2 = ";
  v3.print();

  // Subtraction
  Vector v4 = v2 - v1;
  std::cout << "v2 - v1 = ";
  v4.print();

  // Equality
  std::cout << "v1 == v2: " << (v1 == v2) << std::endl;

  // Less than
  std::cout << "v1 < v2: " << (v1 < v2) << std::endl;

  // Greater than
  std::cout << "v1 > v2: " << (v1 > v2) << std::endl;

  return 0;
}
