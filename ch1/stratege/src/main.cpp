
#include "mallard_duck.h"
#include "model_duck.h"

int main(void) {
  Duck* mallard = new MallardDuck();
  
  mallard->performQuack();
  mallard->performFly();
  
  delete mallard;

  Duck* model = new ModelDuck();
 // FlyBehavior* fly = new FlyWithRocket();
  model->performFly();
  model->setFlyBehavior(new FlyWithRocket());
  model->performFly();
//  delete fly;
  delete model;

  return 0;
}
