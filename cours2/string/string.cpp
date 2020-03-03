#include "./string.hpp"

string::string(const char* original) {
  int size = std::strlen(original) + 1;
  this->data = new char[size];
  std::memcpy(this->data, original, size);
}

string::string(const string& other) {
  size_t size = std::strlen(other.data) + 1;
  this->data = new char[size];
  std::memcpy(data, other.data, size);
}

string::string(string&& rString) {
  this->data = rString.data;
  rString.data = nullptr;
}

string::~string() {
  if(data != nullptr) {
    delete[] this->data;
  }
}

string& string::operator = (string&& other) {
  this->data = other.data;
  other.data = nullptr;
  return *this;
}

string& string::operator = (const char * other) {
  delete[] this->data;
  this->data = new char[std::strlen(other)];
  std::memcpy(this->data, other, std::strlen(other));
  return *this;
}

string string::operator + (const char * other) {
  size_t size = std::strlen(other) + std::strlen(this->data) + 1;
  char * newData = new char[size];
  std::memcpy(newData, this->data, std::strlen(this->data));
  std::memcpy(newData + std::strlen(this->data), other, std::strlen(other) + 1);

  return string(newData);
}

string string::operator + (string& other) {
  return *this + other.data;
}

std::ostream& operator<<(std::ostream& os, const string& str) {
  return os << str.data;
}
