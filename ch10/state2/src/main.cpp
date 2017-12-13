#include <iostream>
#include "gumball.h"

int main(void) {
  GumballMachine*gumballMachine = new GumballMachine(5);
  
  gumballMachine->InsertQuarter();
  gumballMachine->TurnCrank();
  
  gumballMachine->InsertQuarter();
  gumballMachine->EjectQuarter();
  gumballMachine->TurnCrank();
  
  gumballMachine->InsertQuarter();
  gumballMachine->TurnCrank();
  gumballMachine->InsertQuarter();
  gumballMachine->TurnCrank();
  gumballMachine->EjectQuarter();

  gumballMachine->InsertQuarter();
  gumballMachine->InsertQuarter();
  gumballMachine->TurnCrank();
  gumballMachine->InsertQuarter();
  gumballMachine->TurnCrank();
  gumballMachine->InsertQuarter();
  gumballMachine->TurnCrank();
  delete gumballMachine;
}
