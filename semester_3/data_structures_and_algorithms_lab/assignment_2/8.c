#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void inputMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

void countNonZeroElements(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS],
                          int nonZeroCount[MAX_ROWS]) {
  for (int i = 0; i < rows; i++) {
    nonZeroCount[i] = 0;
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] != 0) {
        nonZeroCount[i]++;
      }
    }
  }
}

void printNonZeroCount(int rows, int nonZeroCount[MAX_ROWS]) {
  printf("Number of non-zero elements in each row:\n");
  for (int i = 0; i < rows; i++) {
    printf("Row %d: %d non-zero elements\n", i + 1, nonZeroCount[i]);
  }
}

int main() {
  int rows, cols;
  int matrix[MAX_ROWS][MAX_COLS], nonZeroCount[MAX_ROWS];

  printf("Enter the number of rows and columns of the matrix: ");
  scanf("%d %d", &rows, &cols);

  inputMatrix(rows, cols, matrix);

  countNonZeroElements(rows, cols, matrix, nonZeroCount);

  printNonZeroCount(rows, nonZeroCount);

  return 0;
}
