#include "./SDLException.hpp"

SDLException::SDLException() {
    this->msg = std::string(SDL_GetError() + (std::string("SDL Encountered")));
}

const char* SDLException::what() const throw() {
    return this->msg.c_str();
}