#include <iostream>

#include "weather_data.h"
#include "display.h"

int main(void) {
  WeatherData* weatherData = new WeatherData();

  Observer* currentDisplay =
      new CurrentConditionsDisplay();
  Observer* statiisticsDisplay = 
      new StatisticsDisplay();
  Observer* forecastDisplay = 
      new ForecastDisplay();

  weatherData->registerObserver(currentDisplay);
  weatherData->registerObserver(statiisticsDisplay);
  weatherData->registerObserver(forecastDisplay);
  weatherData->setMeasurements(80, 65, 30.4f);
  weatherData->setMeasurements(82, 70, 29.2f);
  weatherData->setMeasurements(78, 90, 29.2f);

  std::cout << "remove currentDisplay" << std::endl;
  weatherData->removeObserver(currentDisplay);
  weatherData->setMeasurements(12, 13, 14.2f);

  delete currentDisplay;
  delete statiisticsDisplay;
  delete forecastDisplay;

  delete weatherData;

  return 0;
}
