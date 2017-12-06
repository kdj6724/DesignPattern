#ifndef CONDIMENT_H_
#define CONDIMENT_H_
#include <string>
#include "component.h"

class Mocha : public CondimentDecorator {
private:
  Beverage* beverage_;
public:
  Mocha(Beverage* beverage) {
    beverage_ = beverage;
  }
  virtual std::string getDescription() {
    return beverage_->getDescription() + ", Mocha";
  }
  virtual double cost() {
    return beverage_->cost() + .20;
  }
};

class Whip : public CondimentDecorator {
private:
  Beverage* beverage_;
public:
  Whip(Beverage* beverage) {
    beverage_ = beverage;
  }
  virtual std::string getDescription() {
    return beverage_->getDescription() + ", Whip";
  }
  virtual double cost() {
    return beverage_->cost() + .10;
  }
};

class Soy : public CondimentDecorator {
private:
  Beverage* beverage_;
public:
  Soy(Beverage* beverage) {
    beverage_ = beverage;
  }
  virtual std::string getDescription() {
    return beverage_->getDescription() + ", Soy";
  }
  virtual double cost() {
    return beverage_->cost() + .30;
  }
};
#endif  //  CONDIMENT_H_
