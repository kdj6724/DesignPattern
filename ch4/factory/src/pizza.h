#ifndef PIZZA_H_
#define PIZZA_H_
#include <iostream>
#include <vector>
#include <string>

class Pizza {
protected:
  std::string name_;
  std::string dough_;
  std::string sauce_;
  
public:
  void prepare() {
    std::cout << "Preparing " << name_ << std::endl;
    std::cout << "Tossing dough..." << std::endl;
    std::cout << "Adding sauce..." << std::endl;
    std::cout << "Adding toppings: " << std::endl;
  }

  void bake() {
    std::cout << "Bake for 25min at 350" << std::endl;
  }

  void cut() {
    std::cout << "Cutting the pizza into diagonal slices" 
        << std::endl;
  }

  void box() {
    std::cout << "Place pizza in official PizzaStore box"
        << std::endl;
  }

public:
  std::string getName() {
    return name_;
  }
};

class NYStyleCheesePizza : public Pizza {
public:
  NYStyleCheesePizza() {
    name_ = "NY Style Sauce and Cheese Pizza";
    dough_ = "Thin Crust Dough";
    sauce_ = "Marinara Sauce";
  }
};

class ChicagoStyleCheesePizza : public Pizza {
public:
  ChicagoStyleCheesePizza() {
    name_ = "Chicago Style Deep Dish Cheese Pizza";
    dough_ = "Extra Thick Crust Dough";
    sauce_ = "Plum Tomato Sauce";
  }
  void cut() {
    std::cout << "Cutting the pizza into square slices" 
        << std::endl;
  }
};
#endif  // PIZZA_H_
