#ifndef STRING_HPP
#define STRING_HPP
#include <iostream>
#include<cstring>

class string {
  char* data = nullptr;

  public:
    friend std::ostream& operator<<(std::ostream&, const string & str);
    string(const char* original);
    string(const string& other);
    string(string&& rString);
    ~string();
    string& operator = (string&& other);
    string& operator = (const char * other);
    string operator + (const char * other);
    string operator + (string& other);
};
std::ostream& operator<<(std::ostream& os, const string& str);

#endif