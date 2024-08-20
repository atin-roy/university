/*20. Write a class IntArray for one dimensional integer array. Implement the
necessary constructor, copy constructor, and destructor (if necessary) in this
class. Implement other member functions to perform operations, such adding two
arrays, reversing an array, sorting an array etc. Create an IntArray object
having elements 1, 2 and 3 in it. Print its elements. Now, create another
IntArray object which is an exact copy of the previous object. Print its
elements. Now, reverse the elements of the last object. Finally print elements
of both the objects.
*/
// todo constructor, copy constructor, destructor
// todo operations -> add two arrays, reverse an array, sort an array, print
// array

#include <iostream>

class IntArray {
private:
  int size;
  int *data;

public:
  // constructors
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

  // member functions
  void insert(int num) {
    size_t newSize = (size + 1) * sizeof(int);
    int *newData = (int *)realloc(data, newSize);

    if (newData != NULL) {
      data = newData;
    }
    data[size] = num;
    size += 1;
  }

  // adds elements of other object into this object, increasing size
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
      // Last i elements are already sorted
      for (int j = 0; j < size - i - 1; j++) {
        if (data[j] > data[j + 1]) {
          // Swap data[j] and data[j + 1]
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