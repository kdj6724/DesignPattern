
#ifndef COMMAND_H_
#define COMMAND_H_
#include "receiver.h"

class Command {
public:
  virtual void Execute() = 0;
  virtual void Undo() = 0;
};

class NoCommand : public Command {
public:
  virtual void Execute() {
  }
  virtual void Undo() {
  }
};

class LightOnCommand : public Command {
private:
  Light* light_;
public:
  LightOnCommand(Light* light) {
    light_ = light;
  }
  void Execute() {
    light_->On();
  }
  void Undo() {
    light_->Off();
  }
};

class LightOffCommand : public Command {
private:
  Light* light_;
public:
  LightOffCommand(Light* light) {
    light_ = light;
  }
  void Execute() {
    light_->Off();
  }
  void Undo() {
    light_->On();
  }
};

class CeilingFanOnCommand : public Command {
private:
  CeilingFan* fan_;
  int prevSpeed_;
public:
  CeilingFanOnCommand(CeilingFan* fan) {
    fan_ = fan;
  }
  void Execute() {
    prevSpeed_ = fan_->GetSpeed();
    fan_->High();
  }
  void Undo() {
    if (prevSpeed_ == CeilingFan::HIGH) {
      fan_->High();
    } else if (prevSpeed_ == CeilingFan::MEDIUM) {
      fan_->Medium();
    } else if (prevSpeed_ == CeilingFan::LOW) {
      fan_->Low();
    } else if (prevSpeed_ == CeilingFan::OFF) {
      fan_->Off();
    }
  }
};

class CeilingFanOffCommand : public Command {
private:
  CeilingFan* fan_;
public:
  CeilingFanOffCommand(CeilingFan* fan) {
    fan_ = fan;
  }
  void Execute() {
    fan_->Off();
  }
  void Undo() {
    fan_->High();
  }
};

class GarageDoorUpCommand : public Command {
private:
  GarageDoor* door_;
public:
  GarageDoorUpCommand(GarageDoor* door) {
    door_ = door;
  }
  void Execute() {
    door_->Up();
    door_->LightOn();
  }
  void Undo() {
    door_->Down();
    door_->LightOff();
  }
};

class GarageDoorDownCommand : public Command {
private:
  GarageDoor* door_;
public:
  GarageDoorDownCommand(GarageDoor* door) {
    door_ = door;
  }
  void Execute() {
    door_->Down();
    door_->LightOff();
  }
  void Undo() {
    door_->Up();
    door_->LightOn();
  }
};

class StreoOnWithCDCommand : public Command {
private:
  Stereo* stereo_;
public:
  StreoOnWithCDCommand(Stereo* stereo) {
    stereo_ = stereo;
  }
  void Execute() {
    stereo_->On();
    stereo_->SetCD();
    stereo_->SetVolume(11);
  }
  void Undo() {
    stereo_->Off();
    stereo_->SetVolume(0);
  }
};

class StreoOffWithCDCommand : public Command {
private:
  Stereo* stereo_;
public:
  StreoOffWithCDCommand(Stereo* stereo) {
    stereo_ = stereo;
  }
  void Execute() {
    stereo_->Off();
    stereo_->SetVolume(0);
  }
  void Undo() {
    stereo_->On();
    stereo_->SetCD();
    stereo_->SetVolume(11);
  }
};

class MacroCommand : public Command {
  Command*[] commands;
};
#endif  // COMMAND_H_
