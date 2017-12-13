#ifndef SIMPLE_REMOTE_H_
#define SIMPLE_REMOTE_H_
#include <iostream>
#include <string>
#include "command.h"

class RemoteControl {
private:
  static const int MAX_CMD = 10;
  Command* onCommands_[MAX_CMD];
  Command* offCommands_[MAX_CMD];
  Command* undoCommand_;
public:
  RemoteControl() {
    Command* noCommands = new NoCommand();
    for (int i=0; i<MAX_CMD; i++) {
      onCommands_[i] = noCommands;
      offCommands_[i] = noCommands;
    }
    undoCommand_ = noCommands;
  }
  void SetCommand(int slot, Command* onCommand, Command* offCommand) {
    if (slot > MAX_CMD)
      return;
    onCommands_[slot] = onCommand;
    offCommands_[slot] = offCommand;
  }

  void OnButtonWasPushed(int slot) {
    onCommands_[slot]->Execute();
    undoCommand_ = onCommands_[slot];
  }

  void OffButtonWasPushed(int slot) {
    offCommands_[slot]->Execute();
    undoCommand_ = offCommands_[slot];
  }

  void undoButtonWasPushed() {
    undoCommand_->Undo();
  }
};
#endif  // SIMPLE_REMOTE_H_
