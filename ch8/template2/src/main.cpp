#include "abstract.h"
#include "concrete.h"

int main(void) {
  Tea* tea = new Tea();
  Coffee* coffee = new Coffee();

  tea->PrepareRecipe();
  coffee->PrepareRecipe();
}
