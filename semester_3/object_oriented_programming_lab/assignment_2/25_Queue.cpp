#include <iostream>

using namespace std;

class Queue {
private:
  int *data;
  int front;
  int rear;
  int size;

public:
  Queue(int n) : size(n) {
    data = new int[n];
    front = -1;
    rear = -1;
  }

  void add(int n) {
    if (rear >= size - 1) {
      throw out_of_range("Queue overflow");
    }

    data[++rear] = n;
    if (front < 0)
      front++;
  }

  int remove() {
    if (front == -1) {
      throw out_of_range("Queue underflow");
    }

    int member = data[0];
    for (int i = 0; i < rear; i++) {
      data[i] = data[i + 1];
    }
    rear--;
    if (rear == -1)
      front = -1;
    return member;
  }

  void disp() const {
    if (front == -1) {
      cout << endl;
      return;
    }

    for (int i = front; i <= rear; i++) {
      cout << data[i];
      if (i != rear)
        cout << ",";
    }
    cout << endl;
  }
};

int main() {
  Queue q(10);

  q.add(2);
  q.add(3);
  q.add(4);
  q.add(5);

  q.remove();
  q.remove();

  cout << "Queue after removing two elements: ";
  q.disp();
}
