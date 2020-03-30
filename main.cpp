#include "./SDLProgram.hpp"

int main() {
  SDLProgram myWindow = SDLProgram(800, 600);
  myWindow.loop();

  return 0;
}