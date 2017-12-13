
#include "receiver.h"
#include "command.h"
#include "invoker.h"

int main(void) {
  RemoteControl* remoteControl = new RemoteControl();
  Light* livingRoomLight = new Light("Living Room");
  Light* kitchenLight = new Light("Kitchen");
  CeilingFan* ceilingFan = new CeilingFan("Living Room");
  GarageDoor* garageDoor = new GarageDoor("");
  Stereo* stereo = new Stereo("Living Room");

  // Light cmd
  LightOnCommand* livingRoomLightOn =
      new LightOnCommand(livingRoomLight);
  LightOffCommand* livingRoomLightOff =
      new LightOffCommand(livingRoomLight);
  LightOnCommand* kitchenLightOn =
      new LightOnCommand(kitchenLight);
  LightOffCommand* kitchenLightOff =
      new LightOffCommand(kitchenLight);
  //CeilingFan cmd
  CeilingFanOnCommand* ceilingFanOn =
      new CeilingFanOnCommand(ceilingFan);
  CeilingFanOffCommand* ceilingFanOff =
      new CeilingFanOffCommand(ceilingFan);
  // GarageDoor cmd
  GarageDoorUpCommand* garageDoorUp =
      new GarageDoorUpCommand(garageDoor);
  GarageDoorDownCommand* garageDoorDown =
      new GarageDoorDownCommand(garageDoor);
  // Stereo cmd
  StreoOnWithCDCommand* stereoOnWithCD =
      new StreoOnWithCDCommand(stereo);
  StreoOffWithCDCommand* stereoOff =
      new StreoOffWithCDCommand(stereo);

  remoteControl->SetCommand(0, livingRoomLightOn, 
      livingRoomLightOff);
  remoteControl->SetCommand(1, kitchenLightOn, kitchenLightOff);
  remoteControl->SetCommand(2, ceilingFanOn, ceilingFanOff);
  remoteControl->SetCommand(3, stereoOnWithCD, stereoOff);

  remoteControl->OnButtonWasPushed(0);
  remoteControl->OffButtonWasPushed(0);
  remoteControl->undoButtonWasPushed();
  remoteControl->OnButtonWasPushed(1);
  remoteControl->OffButtonWasPushed(1);
  remoteControl->undoButtonWasPushed();
  remoteControl->OnButtonWasPushed(2);
  remoteControl->OffButtonWasPushed(2);
  remoteControl->undoButtonWasPushed();
  remoteControl->OnButtonWasPushed(3);
  remoteControl->OffButtonWasPushed(3);
  remoteControl->undoButtonWasPushed();

  return 0;
}
