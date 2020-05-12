#include <iostream>
#include <thread>
#include <mutex>

std::mutex res_mutex;

void doSomeMath(double max, double* res) {
  double a = 0;
  for(double i = 1; i < max; i++) {
    a += i;
  }
  res_mutex.lock();
  *res = a;
  res_mutex.unlock();
  std::cout << "Result for " << max << "is "<< a << std::endl;
}

int main() {
  double * res = new double(0);
  std::thread t1(doSomeMath, 1000000000, res);
  std::thread t2(doSomeMath, 3000000000, res);
  
  t1.join();
  t2.join();
  std::cout << "Sum of results: " << *res + *res << std::endl;
  delete res;
  return 0;
}