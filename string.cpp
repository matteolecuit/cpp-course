#include <iostream>
#include <cstring>

class string {
  private:
    char* data = nullptr;
  public:
    string(const char* original) {
      std::cout << "Constructor" << std::endl;
      int size = std::strlen(original) + 1;
      this->data = new char[size];
      std::memcpy(this->data, original, size);
    }

    string(const string& other) {
      std::cout << "Copy Construct" << std::endl;
      size_t size = std::strlen(other.data) + 1;
      this->data = new char[size];
      std::memcpy(data, other.data, size);
    }

    string(string&& rString) {
      std::cout << "Move constructor" << std::endl;
      this->data = rString.data;
      rString.data = nullptr;
    }

    ~string() {
      std::cout << "Destructor" << std::endl;
      if(data != nullptr) {
        delete[] this->data;
      }
    }


    string& operator = (string&& other) {
      std::cout << "Copy assign" << std::endl;
      this->data = other.data;
      other.data = nullptr;
      return *this;
    }

    string operator + (const char *  other) {
      std::cout << "+ operator" << std::endl;
      size_t size = std::strlen(other) + std::strlen(this->data) + 1;
      char * newData = new char[size];
      std::memcpy(newData, this->data, std::strlen(this->data));
      std::memcpy(newData + std::strlen(this->data), other, std::strlen(other) + 1);

      return string(newData);
    }

    string operator + (string& other) {
      return *this + other.data;
    }

    char* getChar() {
      return this->data;
    }
};

int main() {
  std::cout << "Start" << std::endl;

  string myString("Hello World");
  std::cout << myString.getChar() << std::endl;

  string myString2(myString);
  std::cout << myString2.getChar() << std::endl;

  string myString3("coucou la planete");
  std::cout << myString3.getChar() << std::endl;

  myString = myString2 + myString3;
  std::cout << myString.getChar() << std::endl;

  std::cout << "End" << std::endl;
  return 0;
}