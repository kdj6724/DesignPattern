#ifndef STATE_H_
#define STATE_H_
#include "context.h"

class State {
public:
  virtual void InsrtQuarter() = 0;
  virtual void EjectQuarter() = 0;
  virtual void TurnCrank() = 0;
  virtual void Dispense() = 0;
};

class NoQuarterState : public State {
private:
  GumballMachine* gumballMachine_;
public:
  NoQuarterState(GumballMachine* gumballMachine) {
    gumballMachine_ = gumballMachine;
  }
  void InsertQuarter() {
    std::cout << "[NoQuarterState]" << std::endl;
    std::cout << "You inserted a quarter" << std::endl;
    gumballMachine->setState(gumballMachine->GetHasQuarterState());
  }
  void EjectQuarter() {
    std::cout << "[NoQuarterState]" << std::endl;
    std::cout << "You have not inserted a quarter" << std::endl;
  }
  void TurnCrank() {
    std::cout << "[NoQuarterState]" << std::endl;
    std::cout << "You turned, but there's no quarter" << std::endl;
  }
  void Dispense() {
    std::cout << "[NoQuarterState]" << std::endl;
    std::cout << "You need to pay first" << std::endl;
  }
};

class HasQuarterState : public State {
private:
  GumballMachine* gumballMachine_;
public:
  HasQuarterState(GumballMachine gumballMachine) {
    gumballMachine_ = gumballMachine;
  }
  void InsertQuarter() {
    std::cout << "[HasQuarterState]" << std::endl;
    std::cout << "You can not insert another quarter" << std::endl;
  }
  void EjectQuarter() {
    std::cout << "[HasQuarterState]" << std::endl;
    std::cout << "Quarter returned" << std::endl;
    gumballMachine->setState(gumballMachine->GetNoQuarterState());
  }
  void TurnCrank() {
    std::cout << "[HasQuarterState]" << std::endl;
    std::cout << "You turned..." << std::endl;
    gumballMachine->setState(gumballMachine->GetSoldState());
  }
  void Dispense() {
    std::cout << "[HasQuarterState]" << std::endl;
    std::cout << "No gumball dispensed" << std::endl;
  }
};

class SoldState : public State {
private:
  GumballMachine* gumballMachine_;
public:
  SoldState(GumballMachine gumballMachine) {
    gumballMachine_ = gumballMachine;
  }
  void InsertQuarter() {
    std::cout << "[SoldState]" << std::endl;
    std::cout << "Please wait, we are already giving you a gumball" 
        << std::endl;
  }
  void EjectQuarter() {
    std::cout << "[SoldState]" << std::endl;
    std::cout << "Sorry, you already truned the crank" << std::endl;
  }
  void TurnCrank() {
    std::cout << "[SoldState]" << std::endl;
    std::cout << "Turning twice does not get you another gumball!" 
        << std::endl;
  }
  void Dispense() {
    std::cout << "[SoldState]" << std::endl;
    gumballMachine_->ReleaseBall();
    if (gumballMachine_->GetCount() > 0) {
      gumballMachine_->SetState(gumballMachine_->GetNoQuarterState());
    } else {
      std::cout << "Out of gumballs!" << std::endl;
      gumballMachine_->SetState(gumballMachine_->GetSoldOutState());
    }
  }
};

class WinnerState : public State {
private:
  GumballMachine* gumballMachine_;
public:
  WinnerState(GumballMachine gumballMachine) {
    gumballMachine_ = gumballMachine;
  }
  void InsertQuarter() {
    std::cout << "[WinnerState]" << std::endl;
    std::cout << "Please wait, we are already giving you a gumball" 
        << std::endl;
  }
  void EjectQuarter() {
    std::cout << "[WinnerState]" << std::endl;
    std::cout << "Sorry, you already truned the crank" << std::endl;
  }
  void TurnCrank() {
    std::cout << "[WinnerState]" << std::endl;
    std::cout << "Turning twice does not get you another gumball!" 
        << std::endl;
  }
  void Dispense() {
    std::cout << "[WinnerState]" << std::endl;
    gumballMachine_->ReleaseBall();
    if (gumballMachine_->GetCount() == 0) {
      gumballMachine_->SetState(gumballMachine_->GetSoldOutState());
    } else {
      gumballMachine_->ReleaseBall();
      if (gumballMachine_->GetCount() > 0) {
        gumballMachine_->SetState(gumballMachine_->GetNoQuarterState());
      } else {
        gumballMachine_->SetState(gumballMachine_->GetSoldOutState());
      }
    }
  }
};

class SoldOutState : public State {
private:
  GumballMachine* gumballMachine_;
public:
  SoldOutState(GumballMachine gumballMachine) {
    gumballMachine_ = gumballMachine;
  }
  void InsertQuarter() {
    std::cout << "[SoldOutState]" << std::endl;
    std::cout << "Sorry" << std::endl;
  }
  void EjectQuarter() {
    std::cout << "[SoldOutState]" << std::endl;
    std::cout << "Sorry" << std::endl;
  }
  void TurnCrank() {
    std::cout << "[SoldOutState]" << std::endl;
    std::cout << "Sorry" << std::endl;
  }
  void Dispense() {
    std::cout << "[SoldOutState]" << std::endl;
    std::cout << "Sorry" << std::endl;
  }
};
#endif  //  STATE_H_
