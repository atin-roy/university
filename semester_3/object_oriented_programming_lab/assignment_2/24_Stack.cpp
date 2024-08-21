#include <iostream>

using namespace std;

class Stack {
  int *buffer;
  int top;
  int size;

public:
  Stack(int n = 0) : size(n) {
    buffer = new int[n];
    top = -1;
  }

  ~Stack() { delete[] buffer; }

  void push(int n) {
    if (top >= size - 1)
      throw out_of_range("Stack overflow.");
    buffer[++top] = n;
  }

  int pop() {
    if (top < 0)
      throw out_of_range("Stack underflow.");
    return buffer[top--];
  }

  void display() const {
    for (int i = top; i >= 0; i--) {
      cout << buffer[i] << endl;
    }
  }
};
int main() {
  Stack stack(5);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  stack.pop();
  stack.display();
}