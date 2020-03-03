#include "./SDLProgram.hpp"

int main() {
  SDLProgram myWindow = SDLProgram(600, 800);
  myWindow.loop();

  return 0;
}