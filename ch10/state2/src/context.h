#ifndef CONTEXT_H_
#define CONTEXT_H_
#include <iostream>

class GumballMachine {
private:
  State* soldOutState_;
  State* noQuarterState_;
  State* hasQuarterState_;
  State* soldState_;
  State* winnerState_;

  State* state_ = soldOutState_;
  int count_ = 0;
public:
  GumballMachine(int numberGumballs) {
    soldOutState_ = new SoldOutState(this);
    noQuarterState_ = new NoQuarterState(this);
    hasQuarterState_ = new HasQuarterState(this);
    soldState_ = new SoldState(this);
    winnerState_ = new WinnerState(this);
    count_ = numberGumballs;
    if (numberGumballs > 0)
      state = noQuarterState_;
    else
      state_ = soldOutState_;
  }
  void InsertQuarter() {
    state_->InsertQuarter();
  }
  void EjectQuarter() {
    state_->EjectQuarter();
  }
  void TurnCrank() {
    state_->TurnCrank();
  }
  void SetState(State* state) {
    state_ = state;
  }
  void ReleaseBall() {
    std::cout << "A gumball comes rolling out the slot..." 
        << std::endl;
    if (count_ != 0)
      count_ = count_ - 1;
  }
  void Dispense() {
    state_->Dispense();
  }
};
#endif  // CONTEXT_H_
