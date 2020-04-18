#include "./SDLProgram.hpp"
#include <vector>

SDLProgram::SDLProgram(int width, int height) {
  this->width = width;
  this-> height = height;
  if (SDL_Init( SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize" << SDL_GetError() << std::endl;
  } else {
    SDL_Window* window = nullptr;
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &this->renderer);
  }
}

SDLProgram::~SDLProgram() {
  SDL_DestroyRenderer(this->renderer);
  SDL_Quit();
}

void SDLProgram::loop() {
  if(this->renderer ==nullptr) {
    return;
  }
  SDL_Event event;
  while(true) {
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
      break;
    }
    this->display();
    SDL_RenderPresent(this->renderer); //Wait for next frame
  }
}

void SDLProgram::display() {
  SDL_Texture *texture;
  texture = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_STREAMING,
    this->height,
    this->width
  );

  std::vector<unsigned char> pixels(this->width*this->height*4);

  SDL_UpdateTexture(
    texture,
    nullptr,
    &pixels[0],
    this->width * 4);
  SDL_RenderCopy(renderer, texture, nullptr, nullptr);
}







