#include <iostream>
using namespace std;

inline int add(int a, int b, int c) { return a + b + c; }

int main() {
  int x = 5, y = 10, z = 15;

  int result = add(x, y, z);
  cout << "The sum of " << x << ", " << y << ", and " << z << " is: " << result
       << endl;

  return 0;
}
