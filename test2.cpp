#include <iostream>

int minus(int w) {
  return -w;
}

int sub(int x, int y) {
  int z = minus(y);
  return x + z;
}

int main () {
  int a = 3;
  int b = 4;
  int c = sub(b,a);
  std::cout << "c equals " << c << std::endl;
  return 0;
}