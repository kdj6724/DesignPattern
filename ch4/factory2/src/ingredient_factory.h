#ifndef INGREDIENT_FACTORY_F_
#define INGREDIENT_FACTORY_F_
class PizzaIngredientFactory {
public:
  virtual Dough* CreateDough() = 0;
  virtual Sauce* CreateSauce() = 0;
  virtual Cheese* CreateCheese() = 0;
  virtual Veggies[]* CreateVeggies() = 0;
  virtual Pepperoni* CreatePepperoni() = 0;
  virtual Clams* CreateClam() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
  virtual Dough* CreateDough() {
    return new ThinCrustDough();
  }

  virtual Sauce* CreateSauce() {
   return new MarinaraSauce();
  }

  virtual Cheese* CreateCheese() {
    return new ReggianoCheese();
  }

  virtual Veggies[]* CreateVeggies() {
    Veggies veggies[] = { new Garlic(), new Onion(), new Mushroot(),
        new RedPepper() };
    return veggies;
  }

  virtual Pepperoni* CreatePepperoni() {
    return new SlicedPepperoni();
  }

  virtual Clams* CreateClam() {
    return new FreshClams();
  }
};
#endif  // INGREDIENT_FACTORY_F_
