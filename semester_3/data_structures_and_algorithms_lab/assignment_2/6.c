#include <stdio.h>
#include <string.h>

void addLargeNumbers(char num1[], char num2[]) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  int maxLen = len1 > len2 ? len1 : len2;
  char result[maxLen + 2];
  int carry = 0, i, sum;

  result[maxLen + 1] = '\0';

  for (i = 0; i < maxLen; i++) {
    int digit1 = (i < len1) ? num1[len1 - 1 - i] - '0' : 0;
    int digit2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0;

    sum = digit1 + digit2 + carry;
    carry = sum / 10;
    result[maxLen - i] = (sum % 10) + '0';
  }

  if (carry) {
    result[0] = carry + '0';
    printf("Sum: %s\n", result);
  } else {
    printf("Sum: %s\n", result + 1);
  }
}

int main() {
  char num1[1000], num2[1000];

  printf("Enter the first large number: ");
  scanf("%s", num1);

  printf("Enter the second large number: ");
  scanf("%s", num2);

  addLargeNumbers(num1, num2);

  return 0;
}
