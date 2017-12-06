
#ifndef COMMAND_H_
#define COMMAND_H_
#include "vendor.h"

class Command {
public:
  virtual void Execute() = 0;
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
};
#endif  // COMMAND_H_
