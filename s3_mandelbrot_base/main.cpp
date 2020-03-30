#include <chrono>
#include <iostream>
#include "./SDLProgram.hpp"
#include "./Mandelbrot.hpp"
#include "./SDLException.hpp"

int main(){
  int width = 800;
  int height = 800;
  Mandelbrot mandelbrot(width, height, -2.1, 0.6, -1.2, 1.2, 20);
  try {
    SDLProgram program(width,height);
    std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
    for(int y = 0; y < height; y++) {
      program.updateLine(y, mandelbrot.drawLine(y));
    }
    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count() << std::endl;
    program.loop();

  } catch(SDLException& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}