#include <iostream>
#include <cstring>
#include <utility>

class Student {
  private:
    float* grades = nullptr;
    int numberOfGrades = 0;
  public:
    Student() {
      std::cout << "Wow, a new student is alive !" << std::endl;
      grades = new float[30];
    }

    Student(const Student& otherStudent) {
      std::cout << "Copy Constructing student" << std::endl;
      this->numberOfGrades = otherStudent.numberOfGrades;
      this->grades = new float[30];
      std::memcpy(this->grades, otherStudent.grades, 30 * sizeof(float));
    }

    Student& operator = (Student otherStudent) {
      std::cout << "Copy Assigning student" << std::endl;
      this->numberOfGrades = otherStudent.numberOfGrades;
      std::swap(this->grades, otherStudent.grades);
      return *this;
    }

    void addGrade(float newGrade) {
      this->grades[this->numberOfGrades] = newGrade;
      this->numberOfGrades++;
    }

    float getGradesAverage() {
      float avg = 0.0;
      for(int i = 0; i < this->numberOfGrades; i++) {
        avg += this->grades[i];
      }
      return avg / this->numberOfGrades;
    }

    ~Student() {
      std::cout << "RIP in Peace you poor student" << std::endl;
      delete[] this->grades;
    }
};

int main() {
  Student s1;
  s1.addGrade(12.2);
  s1.addGrade(14.6);
  s1.addGrade(4.6);
  Student s2;
  s2 = s1;
  std::cout << s1.getGradesAverage() << std::endl;
  return 0;
}