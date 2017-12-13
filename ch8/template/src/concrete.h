#ifndef CONCRETE_H_
#define CONCRETE_H_
#include <iostream>
#include "abstract.h"

class Tea : public CoffeineBeverage {
  virtual void Brew() {
    std::cout << "Steeping the tea" << std::endl;
  }
  virtual void AddCondiments() {
    std::cout << "Pouring into cup" << std::endl;
  }
};

class Coffee : public CoffeineBeverage {
  virtual void Brew() {
    std::cout << "Dripping Coffee through filter" << std::endl;
  }
  virtual void AddCondiments() {
    std::cout << "Adding Sugar and Milk" << std::endl;
  }
};
#endif  // CONCRETE_H_
