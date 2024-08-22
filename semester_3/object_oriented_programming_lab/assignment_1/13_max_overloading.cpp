#include <iostream>
using namespace std;

int max(int a, int b, int c) {
  if (a >= b && a >= c)
    return a;
  else if (b >= a && b >= c)
    return b;
  else
    return c;
}

int max(int arr[], int size) {
  int maxVal = arr[0];
  for (int i = 1; i < size; ++i) {
    if (arr[i] > maxVal)
      maxVal = arr[i];
  }
  return maxVal;
}

int main() {
  int a = 10, b = 15, c = 5;
  cout << "The maximum of " << a << ", " << b << ", and " << c << " is "
       << max(a, b, c) << endl;

  int arr[] = {1, 2, 3, 4, 5, 10, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << "The maximum element in the array is " << max(arr, size) << endl;

  return 0;
}
