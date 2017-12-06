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
    Pizza* pizza = NULL;
    PizzaIngredientFactory ingredientFactory =
        new NYPizzaIngredientFactory();

    if (type == "cheese") {
      pizza = new CheesePizza(ingredientFactory);
      pizza.SetName("New Yory Cheese");
    } else if (type == "clam") {
      pizza = new ClamPizza(ingredientFactory);
      pizza.SetName("New Yory Clam");
    }
    return pizza;
  }
};
#endif // PIZZA_STORE_H_
