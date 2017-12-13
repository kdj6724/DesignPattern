#ifndef MENUITEM_H_
#define MENUITEM_H_
#include <string>

class MenuItem {
protected:
  std::string name_;
  std::string description_;
  bool vegetarian_;
  double price_;
public:
  MenuItem(std::string name, std::string description,
      bool vegetarian, double price) {
    name_ = name;
    description_ = description;
    vegetarian_ = vegetarian;
    price_ = price;
  }

  std::string GetName() {
    return name_;
  }

  std::string GetDescription() {
    return description_;
  }

  double GetPrice() {
    return price_;
  }

  bool IsVegetarian() {
    return vegetarian_;
  }
};
#endif  // MENUITEM_H_
