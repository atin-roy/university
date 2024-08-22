
#include <iostream>

using namespace std;

class Complex {
private:
  float real;
  float imaginary;

public:
  Complex(float r = 0, float i = 0) : real(r), imaginary(i) {}

  void setReal(float real) { this->real = real; }

  void setImg(float imaginary) { this->imaginary = imaginary; }

  float getReal() const { return real; }

  float getImg() const { return imaginary; }

  void disp() const { cout << "(" << real << " + " << imaginary << "j" << ")"; }

  Complex sum(Complex &other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
  }
};

int main() {
  Complex num1(2, 4);
  Complex num2(3.5, 3.14);
  Complex sum = num1.sum(num2);

  cout << "complex number 1 : ";
  num1.disp();
  cout << endl;
  cout << "complex number 2 : ";
  num2.disp();
  cout << endl;
  cout << "Sum : ";
  sum.disp();

  return 0;
}
