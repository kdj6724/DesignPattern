#ifndef DUCK_H_
#define DUCK_H_
#include <iostream>

class Duck {
public:
  virtual void Quack() = 0;
  virtual void Fly() = 0;
};

class MallardDuck : public Duck {
public:
  virtual void Quack() {
    std::cout << "Quack" << std::endl;
  }
  virtual void Fly() {
    std::cout << "Flying" << std::endl;
  }
};
#endif  //  DUCK_H_
