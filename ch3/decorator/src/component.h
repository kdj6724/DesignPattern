#ifndef COMPONENT_H_
#define COMPONENT_H_
#include <string>

class Beverage {
protected:
  std::string description_ = "none";
public:
  virtual std::string getDescription() { return description_; }
  virtual double cost() = 0;
};

class CondimentDecorator : public Beverage {
public:
  virtual std::string getDescription() {
    return "";
  }
  virtual double cont() { return 0; }
};
#endif  // COMPONENT_H_
