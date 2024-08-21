#include <stdio.h>
#include <stdlib.h>

void delete(int **arr, int *size, int indexToDelete) {
  if (*size == 0) {
    return;
  }
  int i;
  for (i = indexToDelete; i < *size - 1; i++) {
    (*arr)[i] = (*arr)[i + 1];
  }
  (*size)--;

  int *temp = (int *)realloc(*arr, (*size) * sizeof(int));
  if (temp == NULL && *size > 0) {
    exit(EXIT_FAILURE);
  }

  *arr = temp;
}

void display(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d", arr[i]);
    if (i != size - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

int main() {
  int i;
  int *arr = (int *)calloc(10, sizeof(int));
  int size = 10;
  printf("Enter 10 elements in the array:\n");
  for (i = 0; i < 10; i++) {
    scanf("%d", &arr[i]);
  }
  display(arr, size);
  delete (&arr, &size, 5);
  display(arr, size);
  delete (&arr, &size, 2);
  display(arr, size);
  printf("The fifth element is %d\n", arr[4]);

  free(arr);

  return 0;
}
