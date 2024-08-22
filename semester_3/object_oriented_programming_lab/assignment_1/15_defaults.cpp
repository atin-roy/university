#include <iostream>
using namespace std;

int add(int a, int b = 0, int c = 0) { return a + b + c; }

int main() {
  cout << "Sum of 1, 2, 3: " << add(1, 2, 3) << endl;

  cout << "Sum of 4, 5: " << add(4, 5) << endl;

  cout << "Sum of 6: " << add(6) << endl;

  return 0;
}
