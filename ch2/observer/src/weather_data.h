#ifndef WEATHER_DATA_H_
#define WEATHER_DATA_H_
#include <iostream>
#include <vector>

#include "observer.h"
#include "subject.h"

class WeatherData : public Subject {
private:
  std::vector<Observer*> list;
  float temperature;
  float humidity;
  float pressure;
public:
  void registerObserver(Observer* obs) {
    list.push_back(obs);
  }
  void removeObserver(Observer* obs) {
    list.erase(std::remove(list.begin(), list.end(), obs), list.end());
  }
  void notifyObservers() {
    for(std::vector<Observer*>::const_iterator iter = list.begin();
        iter != list.end(); ++iter) {
      if (*iter != 0)
        (*iter)->update(temperature, humidity, pressure);
    }
  }

  void measurementsChanged() {
    notifyObservers();
  }

  void setMeasurements(float temperature, float humidity, 
      float pressure) {
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    measurementsChanged();
  }
};
#endif  // WEATHER_DATA_H_
