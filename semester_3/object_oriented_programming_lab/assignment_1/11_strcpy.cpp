#include <iostream>
using namespace std;

void Strcpy(char *const target, const char *const source) {
  int i = 0;
  while (source[i] != '\0') {
    target[i] = source[i];
    i++;
  }
  target[i] = '\0';
}

int main() {
  char source[] = "Hello, World!";
  char target[50];

  Strcpy(target, source);

  cout << "Source: " << source << endl;
  cout << "Target: " << target << endl;

  return 0;
}
