#ifndef VENDOR_H_
#define VENDOR_H_
#include <iostream>

class Light {
public:
  void On() {
    std::cout << "Light On" << std::endl;
  }
  void Off() {
    std::cout << "Light Off" << std::endl;
  }
};
#endif  // VENDOR_H_
