#ifndef SIMPLE_REMOTE_H_
#define SIMPLE_REMOTE_H_
#include "command.h"

class SimpleRemoteControl {
protected:
  Command* slot;
public:
  SimpleRemoteControl() {}
  void SetCommand(Command* command) {
    slot = command;
  }
  void ButtonWasPressed() {
    slot->Execute();
  }
};
#endif  // SIMPLE_REMOTE_H_
