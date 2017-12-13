#ifndef TURKEY_H_
#define TURKEY_H_
#include <iostream>

class Turkey {
public:
  virtual void Gobble() = 0;
  virtual void Fly() = 0;
};

class WildTurkey : public Turkey {
public:
  virtual void Gobble() {
    std::cout << "Gobble" << std::endl;
  }
  virtual void Fly() {
    std::cout << "Flying short distance" << std::endl;
  }
};
#endif  //  TURKEY_H_
