#include <iostream>
#include <stdexcept>

class Vector {
private:
  int *data;
  int size;

public:
  Vector(int size) : size(size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
      data[i] = 0; // Initialize all elements to 0
    }
  }

  Vector(const Vector &other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
      data[i] = other.data[i];
    }
  }

  ~Vector() { delete[] data; }

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

  int &operator[](int index) {
    if (index >= size) {
      throw std::out_of_range("Index out of range.");
    }
    return data[index];
  }

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

  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

  v2[0] = 4;
  v2[1] = 5;
  v2[2] = 6;

  std::cout << "Vector v1: ";
  v1.print();
  std::cout << "Vector v2: ";
  v2.print();

  Vector v3 = v1 + v2;
  std::cout << "v1 + v2 = ";
  v3.print();

  Vector v4 = v2 - v1;
  std::cout << "v2 - v1 = ";
  v4.print();

  std::cout << "v1 == v2: " << (v1 == v2) << std::endl;

  std::cout << "v1 < v2: " << (v1 < v2) << std::endl;

  std::cout << "v1 > v2: " << (v1 > v2) << std::endl;

  return 0;
}
