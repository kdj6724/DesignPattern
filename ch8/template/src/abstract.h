#ifndef ABSTRACT_H_
#define ABSTRACT_H_
#include <iostream>

class CoffeineBeverage {
private:
  void PrepareRecipe() {
    BoilWater();
    Brew();
    PourInCup();
    AddCondiments();
  }
public:
  virtual void Brew() = 0;
  virtual void AddCondiments() = 0;
  virtual void BoilWater() {
    std::cout << "Boiling water" << std::endl;
  }
  virtual void PurInCup() {
    std::cout << "Pouring into cup" << std::endl;
  }
};

#endif  // ABSTRACT_H_
