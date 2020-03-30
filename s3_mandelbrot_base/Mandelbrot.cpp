#include "./Mandelbrot.hpp"

Mandelbrot::Mandelbrot(
  int width,
  int height,
  float xMin,
  float xMax,
  float yMin,
  float yMax,
  int maxIterations) {
  this->width = width;
  this->height = height;
  this->xMin = xMin;
  this->xMax = xMax;
  this->yMin = yMin;
  this->yMax = yMax;
  this->maxIterations = maxIterations;
};

std::vector<unsigned char> Mandelbrot::drawLine() {

};
