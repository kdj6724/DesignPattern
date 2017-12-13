#ifndef INTERATOR_H_
#define INTERATOR_H_
#include <vector>
#include "menuitem.h"
class Interator {
public:
  virtual bool HasNext() = 0;
  virtual MenuItem next() = 0;
};

class PancakeHouseMenuInterator : public Interator {
private:
  int position_ = 0;
  std::vector<MenuItem*> items_;
public:
  PancakeHouseMenuInterator(MenuItem* items) {
    items_ = items;
  }
  MenuItem* Next() {
    MenuItem* menuItem = items_[position_];
    position_++;
    return menuItem;

    return menuItem;
  }
  bool HasNext() {
    if (position_ >= 6 || items_[position_] == NULL)
      return false;

    return true;
  }
};

class DinerMenuIterator : public Interator {
private:
  int position_ = 0;
  MenuItem* items_[6];
public:
  DinerMenuInterator(MenuItem* items) {
    items_ = items;
  }
  MenuItem* next() {
    MenuItem* menuItem = items_[position_];
    position_++;
    return menuItem;
  }
  bool HasNext() {
    if (position_ >= 6 || items_[position_] == NULL)
      return false;

    return true;
  }
};

#endif  // INTERATOR_H_
