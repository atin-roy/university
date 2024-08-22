#include <iostream>

const int CONST_VAL = 100;
#define DEFINE_CONST 200

int &returnByReference(int &a);
inline int inlineFunction(int a, int b);
void functionOverload(int a);
void functionOverload(double b);
void defaultParameters(int a, int b = 10, int c = 20);

int main() {
  auto x = 10;
  auto y = 5.5;
  auto z = "Hello, World!";

  std::cout << "C++ style input/output\n";
  std::cout << "Enter a number: ";
  int num;
  std::cin >> num;
  std::cout << "You entered: " << num << std::endl;

  int integerType = 42;
  double doubleType = 3.14;

  double castExample = 3.14159;
  int castedInt = static_cast<int>(castExample);
  std::cout << "Casted double to int: " << castedInt << std::endl;

  std::cout << "Value of CONST_VAL (global): " << ::CONST_VAL << std::endl;

  const int localConst = 50;
  std::cout << "Constant value: " << localConst << std::endl;

  std::cout << "#define constant value: " << DEFINE_CONST << std::endl;

  const int *ptrConst = &localConst;
  int *const constPtr = &num;

  int a = 10;
  int &refA = a;

  const int &constRefA = a;

  std::cout << "Reference value: " << refA << std::endl;

  int b = 20;
  int &refB = returnByReference(b);
  std::cout << "Returned by reference: " << refB << std::endl;

  int sum = inlineFunction(3, 4);
  std::cout << "Inline function sum: " << sum << std::endl;

  int macroSum = DEFINE_CONST + 50;
  std::cout << "Macro sum: " << macroSum << std::endl;

  functionOverload(5);
  functionOverload(3.14);

  defaultParameters(5);
  defaultParameters(5, 15);
  defaultParameters(5, 15, 25);

  return 0;
}

int &returnByReference(int &a) { return a; }

inline int inlineFunction(int a, int b) { return a + b; }

void functionOverload(int a) {
  std::cout << "Function overload with int: " << a << std::endl;
}

void functionOverload(double b) {
  std::cout << "Function overload with double: " << b << std::endl;
}

void defaultParameters(int a, int b, int c) {
  std::cout << "Values: " << a << ", " << b << ", " << c << std::endl;
}
