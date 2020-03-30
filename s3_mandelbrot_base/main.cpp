#include "./SDLProgram.hpp"
#include "./Mandelbrot.hpp"
#include "./SDLException.hpp"

int main(){
  Mandelbrot mandelbrot(800, 800, -2.1, 0.6, -1.2, 1.2, 20);
  try {
    SDLProgram program(800,800);
    program.loop();

  } catch(SDLException& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}