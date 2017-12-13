#ifndef ADAPTER_H_
#define ADAPTER_H_
#include <iostream>
#include "duck.h"
#include "turkey.h"
class TurkeyAdapter : public Duck {
private:
  Turkey* turkey_;
public:
  TurkeyAdapter(Turkey* turkey) {
    turkey_ = turkey;
  }
  virtual void Quack() {
    turkey_->Gobble();
  }
  virtual void Fly() {
    turkey_->Fly();
    turkey_->Fly();
    turkey_->Fly();
    turkey_->Fly();
    turkey_->Fly();
  }
};
#endif  // ADAPTER_H_
