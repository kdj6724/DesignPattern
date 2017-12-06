#ifndef OBSERVER_H_
#define OBSERVER_H_
class Observer {
public:
  virtual void update(float temp, float humidity, float pressure) = 0;
};
#endif  // OBSERVER_H_
