#include <iostream>
using namespace std;

int main() {
  for (int celsius = 0; celsius <= 100; ++celsius) {
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    cout << celsius << " degree Celsius = " << fahrenheit
         << " degree Fahrenheit" << endl;
  }

  return 0;
}
