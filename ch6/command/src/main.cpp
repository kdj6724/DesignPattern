
#include "receiver.h"
#include "command.h"

int main(void) {
  SimpleRemoteControl* remote = new SimpleRemoteControl();
  Light* light = new Light();
  LightOnCommand* lightOn = new LightOnCommand(light);

  remote->SetCommand(lightOn);
  remote->ButtonWasPressed();
}
