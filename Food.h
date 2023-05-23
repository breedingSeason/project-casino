#ifndef FOOD_H
#define FOOD_H
#include <string>

#include "FnB_menu.h"

using namespace std;

class Food : public FnB_menu {
 private:
  int calories;

 public:
  Food();                                                 // Default constructor
  Food(string name, int stock, int price, int calories);  // Parameterized constructor
  int get_nutrition_info() override;  // Return calories
};

#endif