#include <iostream>
#include <string>

class DivisionByZero: public std::exception {
  public:
    virtual const char* what() throw() {
      return "A Division by Zero was attempted";
    }
};

float division(float a, float b){
  if (b==0.0) {
    throw DivisionByZero();
  }
  return a / b;
};

int main () {
  int a = 4;
  int b = 0;

  try {
    float c = division(a, b);
  } catch (DivisionByZero& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}