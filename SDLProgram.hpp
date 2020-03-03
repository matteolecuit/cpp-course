#ifndef SDLPROGRAM_HPP
#define SDLPROGRAM_HPP
#include <SDL2/SDL.h>
#include <iostream>

class SDLProgram {
  private:
    int width = 640;
    int height = 480;
    SDL_Renderer* renderer = nullptr;
  public:
    SDLProgram(int width, int height);
    void display();
    void loop();
    ~SDLProgram();
};

#endif
