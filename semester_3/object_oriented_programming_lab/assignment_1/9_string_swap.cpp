#include <cstring>
#include <iostream>
using namespace std;

void swap(char str1[], char str2[]) {
  char temp[100];
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}

int main() {
  char str1[100] = "Hello";
  char str2[100] = "World";

  cout << "Before swapping: str1 = " << str1 << ", str2 = " << str2 << endl;

  swap(str1, str2);

  cout << "After swapping: str1 = " << str1 << ", str2 = " << str2 << endl;

  return 0;
}
