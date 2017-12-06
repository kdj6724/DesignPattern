#ifndef COFFEE_H_
#define COFFEE_H_
#include <string>
#include "component.h"

class Espresso : public Beverage {
public:
  Espresso() {
    description_ = "Espresso";
  }
  double cost() {
    return 1.99;
  }
};

class HouseBlend : public Beverage {
public:
  HouseBlend() {
    description_ = "HouseBlend";
  }
  double cost() {
    return .89;
  }
};

class DarkRoast : public Beverage {
public:
  DarkRoast() {
    description_ = "DarkRoast";
  }
  double cost() {
    return 1.29;
  }
};
#endif  // COFFEE_H_
