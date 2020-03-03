#include <iostream>
#include <cstring>
#include <utility>
#include <memory>

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

    Student(Student&& rStudent) {
      std::cout << "move" << std::endl;
      this-> numberOfGrades = rStudent.numberOfGrades;
      this->grades = rStudent.grades;
      rStudent.grades = nullptr;
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

void testPtrFun(std::shared_ptr<Student>& sPtr) {
  sPtr->addGrade(8.0);
};


Student makeAverageStudent(){
  Student s2;
  s2.addGrade(10);
  s2.addGrade(10);
  s2.addGrade(10);
  return s2;
}




int main() {
  /*
  std::weak_ptr<Student> ws;
  {
    std::shared_ptr<Student> s1 = std::make_shared<Student>();
    ws = s1;
    s1->addGrade(12.2);
    s1->addGrade(14.6);
    s1->addGrade(4.6);
    std::cout << "avg: " << s1->getGradesAverage() << std::endl;
    std::cout << "use count: " << s1.use_count() << std::endl;

    if(std::shared_ptr<Student> s2 = ws.lock()) {
      std::cout << "Weak pointer valide"<< std::endl;
    } else {
      std::cout << "Weak pointer non valide"<< std::endl;
    }
  }

  if(std::shared_ptr<Student> s2 = ws.lock()) {
    std::cout << "Weak pointer valide"<< std::endl;
  } else {
    std::cout << "Weak pointer non valide"<< std::endl;
  }
*/
  Student matteo;
  matteo = makeAverageStudent();
  return 0;
};