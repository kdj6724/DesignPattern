#ifndef ABSTRACT_H_
#define ABSTRACT_H_
#include <iostream>

class CoffeineBeverage {
public:
  void PrepareRecipe() {
    BoilWater();
    Brew();
    PurInCup();
    if (CustomerWantsCondiments())
      AddCondiments();
  }
protected:
  virtual void Brew() = 0;
  virtual void AddCondiments() = 0;
  virtual void BoilWater() {
    std::cout << "Boiling water" << std::endl;
  }
  virtual void PurInCup() {
    std::cout << "Pouring into cup" << std::endl;
  }
  bool CustomerWantsCondiments() {
    return true;
  }
};

#endif  // ABSTRACT_H_
