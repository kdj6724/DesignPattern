#ifndef MODEL_DUCK_H_
#define MODEL_DUCK_H_

#include <iostream>
#include "duck.h"

class FlyNoWay : public FlyBehavior {
public:
  virtual void fly() {
    std::cout << "fly no way" << std::endl;
  }
};

class FlyWithRocket : public FlyBehavior {
public:
  virtual void fly() {
    std::cout << "fly with rocket" << std::endl;
  }
};

class ModelDuck : public Duck {
public:
  ModelDuck() {
    std::cout << "ModelDuck constructor" << std::endl;
    quackBehavior = new Quack();
    flyBehavior = new FlyNoWay();
  }
  virtual ~ModelDuck() {
    std::cout << "ModelDuck destructor" << std::endl;
    delete quackBehavior;
    delete flyBehavior;
  }
  virtual void display() {
    std::cout << "ModelDuck display" << std::endl;
  }
};

#endif  // MODEL_DUCK_H_
