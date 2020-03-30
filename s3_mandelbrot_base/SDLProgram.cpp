#include "./SDLProgram.hpp"

SDLProgram::SDLProgram(int width, int height){
    this->width = width;
    this->height = height;
    if (SDL_Init( SDL_INIT_VIDEO ) < 0){
      throw SDLException();
    }
    else{
        SDL_Window* window = nullptr;
        SDL_CreateWindowAndRenderer(this->width, this->height, 0, &window, &this->renderer);
        this->texture = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, this->width, this->height);
    }
}

void SDLProgram::loop(){
    if(this->renderer == nullptr){
        return;
    }
    SDL_Event event;
    while (true) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT){
            break;
        }
        this->display();
        SDL_RenderPresent(this->renderer); //Attente de la prochaine frame
    }
}

void SDLProgram::display(){
  SDL_RenderCopy(this->renderer, this->texture, nullptr, nullptr);
}

void SDLProgram::updateLine(int lineNumber, std::vector<unsigned char> linePixels) {
  SDL_Rect r;
  r.x = 0;
  r.y = lineNumber;
  r.w = this-> width;
  r.h = 1;
  SDL_UpdateTexture(this->texture, &r, &linePixels[0], this->width * 4);
}


SDLProgram::~SDLProgram(){
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}