#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
  int B[ROWS * COLS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int index = i * COLS + j;
      printf("B[%d][%d] = %d\n", i, j, B[index]);
    }
  }

  return 0;
}
