#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include <vector>
#include "menuitem.h"

class PancakeHouseMenu {
private:
  std::vector<MenuItem*>  menuItems_;
public:
  PancakeHouseMenu() {
    AddItem("K&B's Pancake Breakfast",
          "Pancakes with scrambled eggsm and toast", 
          true, 2.99);
    
    AddItem("Regular Pancake Breakfast",
          "Pancakes with fried eggs, sausage", 
          false, 2.99);

    AddItem("Blueberry Pancake",
          "Pancakes maed with frash blueberries", 
          true, 3.49);
    
    AddItem("Waffles",
          "Waffles, with your choice of blueberries or strawberries", 
          true, 3.59);
  }
  void AddItem(std::string name, std::string description
      bool vegetarian, double price) {
    MenuItem* menuItem = new MenuItem(name, description,
        vegetarian, price);
    menuitems_->push_back(menuItem);
  }
};

class DinerMenu {
private:
  int numberOfItems_ = 0;
  MenuItem* menuItems_[6];
public:
  DinerMenu() {
    AddItem("Vegetarian BLT",
        "(Fakin’) Bacon with lettuce & tomato on whole wheat", 
        true, 2.99);
    AddItem("BLT",
        "Bacon with lettuce & tomato on whole wheat", 
        false, 2.99);
    AddItem(“Soup of the day”,
        "Soup of the day, with a side of potato salad", 
        false, 3.29);
    AddItem("Hotdog",
        "A hot dog, with saurkraut, relish, onions, topped with cheese",
        false, 3.05);
  }
  
  void AddItem(std::string name, std::string description
      bool vegetarian, double price) {
    if (numberOfItems >= 6) {
      std::cout << "menu is full" << std::endl;
    } else {
      MenuItem menuItem = new MenuItem(name, description, 
          vegetarian, price);
      menuItems_[numberofItems] = menuItem;
      numberOfItems++;
    }
  }
};
#endif  //  MENU_H_
