#ifndef CONCRETE_H_
#define CONCRETE_H_
#include <iostream>
#include "abstract.h"

class Tea : public CoffeineBeverage {
protected:
  virtual void Brew() {
    std::cout << "Steeping the tea" << std::endl;
  }
  virtual void AddCondiments() {
    std::cout << "Pouring into cup" << std::endl;
  }
};

class Coffee : public CoffeineBeverage {
protected:
  virtual void Brew() {
    std::cout << "Dripping Coffee through filter" << std::endl;
  }
  virtual void AddCondiments() {
    std::cout << "Adding Sugar and Milk" << std::endl;
  }
  bool CustomerWantsCondiments() {
    std::string answer = GetUserInput();
    if (answer == "yes")
      return true;
    else
      return false;
  }
  virtual std::string GetUserInput() {
    std::string answer = "";
    std::cout << "Would you like milk and sugar with your Coffee (y/n)? "
        << std::endl;
    std::cin >> answer;

    return answer;
  }
};
#endif  // CONCRETE_H_
