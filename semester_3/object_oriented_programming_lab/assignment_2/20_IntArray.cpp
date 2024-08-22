#include <iostream>

class IntArray {
private:
  int size;
  int *data;

public:
  IntArray() : size(0), data(nullptr){};

  IntArray(int size) : size(size) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = 0;
    }
  }

  IntArray(const IntArray &other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = other.data[i];
    }
  }

  ~IntArray() { delete[] data; }

  void insert(int num) {
    size_t newSize = (size + 1) * sizeof(int);
    int *newData = (int *)realloc(data, newSize);

    if (newData != NULL) {
      data = newData;
    }
    data[size] = num;
    size += 1;
  }

  void add(const IntArray &other) {
    size_t newSize = (size + other.size) * sizeof(int);
    int *newData = (int *)realloc(data, newSize);

    if (newData != NULL) {
      data = newData;
    }

    for (int i = size; i < size + other.size; i++) {
      data[i] = other.data[i - size];
    }

    size += other.size;
  }

  void reverse() {
    int *start = data;
    int *end = data + size - 1;

    while (start != end) {
      int temp = *start;
      *start = *end;
      *end = temp;
      start += 1;
      end -= 1;
    }
  }

  void sort() {
    for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
        if (data[j] > data[j + 1]) {
          int temp = data[j];
          data[j] = data[j + 1];
          data[j + 1] = temp;
        }
      }
    }
  }

  void print() const {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
      std::cout << data[i];
      if (i != size - 1) {
        std::cout << " ";
      }
    }
    std::cout << "]";
    std::cout << std::endl;
  }
};

int main() {
  IntArray a1;
  a1.insert(1);
  a1.insert(2);
  a1.insert(3);
  std::cout << "IntArray a1: ";
  a1.print();
  IntArray a2(a1);
  std::cout << "IntArray a2: ";
  a2.print();
  a2.reverse();
  std::cout << "After reversing last object, " << std::endl;

  std::cout << "IntArray a1: ";
  a1.print();
  std::cout << "IntArray a2: ";
  a2.print();
  return 0;
}
