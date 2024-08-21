#include <stdio.h>

void reverse(int *first, int *last) {
  int temp;
  while (first < last) {
    temp = *first;
    *first = *last;
    *last = temp;
    first++;
    last--;
  }
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
  int size;
  int i;
  printf("Enter the size of the array\n");
  scanf("%d", &size);

  int arr[size];
  printf("Enter elements in the array:\n");

  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  display(arr, size);

  reverse(arr, arr + size - 1);
  display(arr, size);

  return 0;
}
