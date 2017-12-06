
#include "pizza_store.h"

int main(void) {
  PizzaStore* nyStore = new NYPizzaStore();
  PizzaStore* chicagoStore = new ChcagoPizzaStore();

  Pizza* pizza = nyStore->OrderPizza("cheese");
  std::cout << "Ethan ordered a " << pizza->getName() 
      << std::endl;

  pizza = chicagoStore->OrderPizza("cheese");
  std::cout << "Joel ordered a " << pizza->getName()
      << std::endl;

  return 0;
}
