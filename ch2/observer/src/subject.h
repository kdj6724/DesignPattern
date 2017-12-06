#ifndef SUBJECT_H_
#define SUBJECT_H_

class Subject {
public:
  void registerObserver(Observer obs) {}
  void removeObserver(Observer obs) {}
  void notifyObserver() {}
};
#endif  // SUBJECT_H_
