#include <iostream>
using namespace std;

void print(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void print(int matrix[][3], int rows) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int vector[] = {1, 2, 3, 4, 5};
  int vectorSize = sizeof(vector) / sizeof(vector[0]);
  cout << "One-dimensional array:" << endl;
  print(vector, vectorSize);

  int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
  cout << "Two-dimensional array:" << endl;
  print(matrix, 2);

  return 0;
}
