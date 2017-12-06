#ifndef PIZZA_STORE_H_
#define PIZZA_STORE_H_
#include "pizza.h"

class PizzaStore {
public:
  Pizza* OrderPizza(std::string type) {
    Pizza* pizza;

    pizza = CreatePizza(type);

    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();

    return pizza;
  }
protected:
  virtual Pizza* CreatePizza(std::string type) = 0;
};

class NYPizzaStore : public PizzaStore {
protected:
  virtual Pizza* CreatePizza(std::string type) {
    if (type == "cheese")
      return new NYStyleCheesePizza();

    return NULL;
  }
};

class ChcagoPizzaStore : public PizzaStore {
protected:
  virtual Pizza* CreatePizza(std::string type) {
    if (type == "cheese")
      return new ChicagoStyleCheesePizza();

    return NULL;
  }
};
#endif // PIZZA_STORE_H_
