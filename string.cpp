#include "./string.hpp"

string::string(const char* original) {
  std::cout << "Constructor" << std::endl;
  int size = std::strlen(original) + 1;
  this->data = new char[size];
  std::memcpy(this->data, original, size);
}

string::string(const string& other) {
  std::cout << "Copy Construct" << std::endl;
  size_t size = std::strlen(other.data) + 1;
  this->data = new char[size];
  std::memcpy(data, other.data, size);
}

string::string(string&& rString) {
  std::cout << "Move constructor" << std::endl;
  this->data = rString.data;
  rString.data = nullptr;
}

string::~string() {
  std::cout << "Destructor" << std::endl;
  if(data != nullptr) {
    delete[] this->data;
  }
}

string& string::operator = (string&& other) {
  std::cout << "Copy assign" << std::endl;
  this->data = other.data;
  other.data = nullptr;
  return *this;
}

string& string::operator = (const char * other) {
  std::cout << "= operator" << std::endl;
  delete[] this->data;
  this->data = new char[std::strlen(other)];
  std::memcpy(this->data, other, std::strlen(other));
  return *this;
}

string string::operator + (const char * other) {
  std::cout << "+ operator" << std::endl;
  size_t size = std::strlen(other) + std::strlen(this->data) + 1;
  char * newData = new char[size];
  std::memcpy(newData, this->data, std::strlen(this->data));
  std::memcpy(newData + std::strlen(this->data), other, std::strlen(other) + 1);

  return string(newData);
}

string string::operator + (string& other) {
  return *this + other.data;
}std::ostream& operator<<(std::ostream& os, const string& str) {
  return os << str.data;
}
