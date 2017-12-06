#ifndef MALLARD_DUCK_H_
#define MALLARD_DUCK_H_

#include <iostream>
#include "duck.h"

class FlyWithWings : public FlyBehavior {
public:
  virtual void fly() {
    std::cout << "fly with wings" << std::endl;
  }
};

class MallardDuck : public Duck {
public:
  MallardDuck() {
    std::cout << "MallardDuck constructor" << std::endl;
    quackBehavior = new Quack();
    flyBehavior = new FlyWithWings();
  }
  virtual ~MallardDuck() {
    std::cout << "MallardDuck destructor" << std::endl;
    delete quackBehavior;
    delete flyBehavior;
  }
  virtual void display() {
    std::cout << "MallardDuck display" << std::endl;
  }
};

#endif  // MALLARD_DUCK_H_
