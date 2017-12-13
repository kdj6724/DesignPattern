#include <iostream>
#include "duck.h"
#include "turkey.h"
#include "adapter.h"

int main(void) {
  Duck* duck = new MallardDuck();

  Turkey* turkey = new WildTurkey();
  Duck* turkeyAdapter = new TurkeyAdapter(turkey);
  
  std::cout << "The Turkey says..." << std::endl;
  turkey->Gobble();
  turkey->Fly();

  std::cout << "The Duck says..." << std::endl;
  duck->Quack();
  duck->Fly();

  std::cout << "The TurkeyAdapter says..." << std::endl;
  turkeyAdapter->Quack();
  turkeyAdapter->Fly();

  return 0;
}
