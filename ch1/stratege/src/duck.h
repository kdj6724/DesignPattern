#ifndef DUCK_H_
#define DUCK_H_

#include <iostream>

class FlyBehavior {
public:
  virtual void fly() = 0;
};

class QuackBehavior {
public:
  virtual void quack() = 0;
};

class Quack : public QuackBehavior {
public:
 virtual void quack() {
   std::cout << "quack quack" << std::endl;
 }
};

class Duck {
protected:
  QuackBehavior* quackBehavior;
  FlyBehavior* flyBehavior;
public:
  Duck() : quackBehavior(NULL), flyBehavior(NULL) {
    std::cout << "duck constructor" << std::endl;
    //quackBehavior = new QuackBehavior();
    //flyBehavior = new FlyBehavior();
  }
  virtual ~Duck() {
    std::cout << "duck destructor" << std::endl;
    //delete quackBehavior;
    //delete flyBehavior;
  }

  void performQuack() {
    if (quackBehavior != NULL)
      quackBehavior->quack(); 
  }
  void performFly() {
    if (flyBehavior != NULL)
      flyBehavior->fly();
  }
  virtual void swim() {
    std::cout << "Duck swim" << std::endl;
  }
  virtual void display() {
    std::cout << "Duck display" << std::endl;
  }
  void setFlyBehavior(FlyBehavior* fb) {
    flyBehavior = fb;
  }
  void setQuackBehavior(QuackBehavior* qb) {
    quackBehavior = qb;
  }
};

#endif  // DUCK_H_
