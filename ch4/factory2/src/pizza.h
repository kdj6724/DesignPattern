#ifndef PIZZA_H_
#define PIZZA_H_
#include <iostream>
#include <vector>
#include <string>

class Pizza {
protected:
  std::string name_;
  Dough* dough_;
  Sauce* sauce_;
  Veggies* veggies_[];
  Cheese* cheese_;
  Pepperoni pepperoni_;
  Clams clam_;
  
public:
  virtual void Prepare() = 0;

  void Bake() {
    std::cout << "Bake for 25min at 350" << std::endl;
  }

  void Cut() {
    std::cout << "Cutting the pizza into diagonal slices" 
        << std::endl;
  }

  void Box() {
    std::cout << "Place pizza in official PizzaStore box"
        << std::endl;
  }

public:
  void SetName(std::string name) {
    name_ = name;
  }
  std::string GetName() {
    return name_;
  }
};

class CheesePizza : public Pizza {
private:
  PizzaIngredientFactory* ingredientFactory_;
public:
  CheesePizza(PizzaIngredientFactory* ingredientFactory) { 
    ingredientFactory_ = ingredientFactory;
  }
  virtual Perpare() {
    std::cout << "Perparing " << name_ << std::endl;
    dough_ = ingredientFactory_.CreateDough();
    sauce_ = ingredientFactory_.CreateSauce();
    cheese = ingredientFactory_.CreateCheese();
  }
};

class ClamPizza : public Pizza {
private:
  PizzaIngredientFactory* ingredientFactory_;
public:
  ClamPizza(PizzaIngredientFactory* ingredientFactory) { 
    ingredientFactory_ = ingredientFactory;
  }
  virtual Perpare() {
    std::cout << "Perparing " << name_ << std::endl;
    dough_ = ingredientFactory_.CreateDough();
    sauce_ = ingredientFactory_.CreateSauce();
    cheese_ = ingredientFactory_.CreateCheese();
    clam_ = ingredientFactory_.CreateClam();
  }
};

#endif  // PIZZA_H_
