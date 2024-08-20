/*23. Write the definition for a class called Complex that has private floating
point data members for storing real and imaginary parts. The class has the
following public member functions: setReal() and setImg() to set the real and
imaginary part respectively. getReal() and getImg() to get the real and
imaginary part respectively. disp() to display complex number object sum() to
sum two complex numbers & return a complex number Write main function to create
three complex number objects. Set the value in two objects and call sum() to
calculate sum and assign it in third object. Display all complex numbers.*/

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
  cout << "Sum : "
}