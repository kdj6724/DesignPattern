#ifndef DISPLAY_H_
#define DISPLAY_H_
#include <iostream>

#include "observer.h"
#include "subject.h"

class DisplayElement {
public:
  virtual void display() = 0;
};

// Observer 1
class CurrentConditionsDisplay : public Observer, 
    public DisplayElement {
private:
  float temperature;
  float humidity;
public:
  CurrentConditionsDisplay() {
  }
  void update(float temp, float humidity, float pressure) {
    this->temperature = temp;
    this->humidity = humidity;
    display();
  }
  void display() {
    std::cout << "CurrentCondition -> T:" << temperature << " H:" 
        << humidity << std::endl;
  }
};

// Observer 2
class StatisticsDisplay : public Observer, 
    public DisplayElement {
private:
  float temperature;
  float pressure;
public:
  void update(float temp, float humidity, float pressure) {
    this->temperature = temp;
    this->pressure = pressure;
    display();
  }
  void display() {
    std::cout << "StatisticsDisplay -> T:" << temperature
        << " P:" << pressure << std::endl;
  }
};

// Observer 3
class ForecastDisplay : public Observer, 
    public DisplayElement {
private:
  float humidity;
  float pressure;
public:
  void update(float temp, float humidity, float pressure) {
    this->humidity = humidity;
    this->pressure = pressure;
    display();
  }
  void display() {
    std::cout << "ForecastDisplay -> H:" 
        << humidity << " P:" << pressure << std::endl;
  }
};

// Observer 4
class ThirdPartyDisplay : public Observer, 
    public DisplayElement {
private:
  float temperature;
  float humidity;
  float pressure;
public:
  void update(float temp, float humidity, float pressure) {
    this->temperature = temp;
    this->humidity = humidity;
    this->pressure = pressure;
    display();
  }
  void display() {
    std::cout << "ThirdPartyDisplay -> T:" << temperature << " H:" 
        << humidity << " P:" << pressure << std::endl;
  }
};
#endif  // DISPLAY_H_
