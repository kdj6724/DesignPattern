#ifndef GUM_BALL_H_
#define GUM_BALL_H_
#include <iostream>

class GumballMachine {
private:
  static const int SOLD_OUT = 0;
  static const int NO_QUARTER = 1;
  static const int HAS_QUARTER = 0;
  static const int SOLD = 3;
  int state_ = SOLD_OUT;
  int count_ = 0;
public:
  GumballMachine(int count) {
    count_ = count;
    if (count_ > 0)
      state_ = NO_QUARTER;
  }
  void InsertQuarter() {
    if (state_ == HAS_QUARTER) {
      std::cout << "You can't insert another quarter" << std::endl;
    } else if (state_ == NO_QUARTER) {
      std::cout << "You insert a quarter" << std::endl;
    } else if (state_ == SOLD_OUT) {
      std::cout << "You can't insert  a quarter, sold out" << std::endl;
    } else if (state_ == SOLD) {
      std::cout << "Please wait" << std::endl;
    }
  }
  void EjectQuarter() {
    if (state_ == HAS_QUARTER) {
      std::cout << "Quarter returned" << std::endl;
      state_ = NO_QUARTER;
    } else if (state_ == NO_QUARTER) {
      std::cout << "You haven’t inserted a quarter" << std::endl;
    } else if (state_ == SOLD) {
      std::cout << "Sorry, you already turned the crank" << std::endl;
    } else if (state_ == SOLD_OUT) {
      std::cout << "You can’t eject, you haven’t inserted a quarter yet" 
          << std::endl;
    }
  }
  void TurnCrank() {
    if (state_ == SOLD) {
      std::cout << "Turning twice doesn’t get you another gumball!" 
          << std::endl;
    } else if (state_ == NO_QUARTER) {
      std::cout << "You turned but there’s no quarter" << std::endl;
    } else if (state_ == SOLD_OUT) {
      std::cout << "You turned, but there are no gumballs" << std::endl;
    } else if (state_ == HAS_QUARTER) {
      std::cout << "You turned..." << std::endl;
      state_ = SOLD;
      Dispense();
    }
  }
  void Dispense() {
    if (state_ == SOLD) {
      std::cout << "A gumball comes rolling out the slot" << std::endl;
      count_ = count_ - 1;
    if (count_ == 0) {
      std::cout << "Oops, out of gumballs!" << std::endl;
      state_ = SOLD_OUT;
    } else {
      state_ = NO_QUARTER;
    }
    } else if (state_ == NO_QUARTER) {
      std::cout << "You need to pay first" << std::endl;
    } else if (state_ == SOLD_OUT) {
      std::cout << "No gumball dispensed" << std::endl;
    } else if (state_ == HAS_QUARTER) {
      std::cout << "No gumball dispensed" << std::endl;
    }
  }
};
#endif  // GUM_BALL_H_
