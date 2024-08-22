#include <iostream>
using namespace std;

int main() {
  int factorial = 1;

  for (int i = 1; i <= 6; ++i) {
    factorial *= i;
    cout << i << "! = " << factorial << endl;
  }

  return 0;
}
