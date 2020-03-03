#include "./string.hpp"

int main() {
  string hello("Hello");
  string world("Jambon");
  world = "World";
  string helloWorld = hello + " " + world;
  std::cout << helloWorld << std::endl;

  return 0;
}
