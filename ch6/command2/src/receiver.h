#ifndef VENDOR_H_
#define VENDOR_H_
#include <iostream>
#include <string>

class Light {
private:
  std::string name_;
public:
  Light(std::string name) {
    name_ = name;
  }
  void On() {
    std::cout << "Light On" << std::endl;
  }
  void Off() {
    std::cout << "Light Off" << std::endl;
  }
};

class Stereo {
private:
  std::string name_;
public:
  Stereo(std::string name) {
    name_ = name;
  }
  void On() {
    std::cout << "Stereo On" << std::endl;
  }
  void Off() {
    std::cout << "Stereo Off" << std::endl;
  }
  void SetCD() {
    std::cout << "Stereo SetCD" << std::endl;
  }
  void SetDVD() {
    std::cout << "Stereo SetDVD" << std::endl;
  }
  void SetRadio() {
    std::cout << "Stereo SetRadio" << std::endl;
  }
  void SetVolume(int volume) {
    std::cout << "Stereo SetVolume : " << volume << std::endl;
  }
};

class CeilingFan {
private:
  std::string name_;
  int speed_;
  std::string location_;
public:
  static const int HIGH = 3;
  static const int MEDIUM = 2;
  static const int LOW = 1;
  static const int OFF = 0;
  CeilingFan(std::string location) {
    location_ = location;
    speed_ = OFF;
  }
  void High() {
    std::cout << "CeilingFan Speed H" << std::endl;
    speed_ = HIGH;
  }
  void Medium() {
    std::cout << "CeilingFan Speed M" << std::endl;
    speed_ = MEDIUM;
  }
  void Low() {
    std::cout << "CeilingFan Speed L" << std::endl;
    speed_ = LOW;
  }
  void Off() {
    std::cout << "CeilingFan Off" << std::endl;
    speed_ = OFF;
  }
  int GetSpeed() {
    return speed_;
  }
};

class GarageDoor {
private:
  std::string name_;
public:
  GarageDoor(std::string name) {
    name_ = name;
  }
  void Up() {
    std::cout << "GargaeDoor Up" << std::endl;
  }
  void Down() {
    std::cout << "GargaeDoor Down" << std::endl;
  }
  void Stop() {
    std::cout << "GargaeDoor Stop" << std::endl;
  }
  void LightOn() {
    std::cout << "GargaeDoor Light On" << std::endl;
  }
  void LightOff() {
    std::cout << "GargaeDoor Light Off" << std::endl;
  }
};
#endif  // VENDOR_H_
