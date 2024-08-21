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

void addMatrices(int rows, int cols, int matrix1[MAX_ROWS][MAX_COLS],
                 int matrix2[MAX_ROWS][MAX_COLS],
                 int result[MAX_ROWS][MAX_COLS]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void printMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
  printf("Resultant Matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int rows, cols;
  int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS],
      result[MAX_ROWS][MAX_COLS];

  printf("Enter the number of rows and columns of the matrices: ");
  scanf("%d %d", &rows, &cols);

  printf("Enter the first matrix:\n");
  inputMatrix(rows, cols, matrix1);

  printf("Enter the second matrix:\n");
  inputMatrix(rows, cols, matrix2);

  addMatrices(rows, cols, matrix1, matrix2, result);

  printMatrix(rows, cols, result);

  return 0;
}
