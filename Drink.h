#ifndef DRINK_H
#define DRINK_H
#include <string>

#include "FnB_menu.h"
using namespace std;

class Drink : public FnB_menu {
 private:
  int alcohol_percentage;

 public:
  Drink();  // Default constructor
  Drink(string name, int stock, int price, int alcohol_percentage);  // Parameterized constructor
  int get_nutrition_info() override;  // Returns alcohol_percentage
};
#endif