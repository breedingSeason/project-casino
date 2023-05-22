#include "Drink.h"

#include <iostream>
#include <string>
Drink::Drink() : FnB_menu(), alcohol_percentage(0){};

Drink::Drink(string name, int stock, int price, int alcohol_percentage)
    : FnB_menu(string name, int stock, int price) {
  this->alcohol_percentage = alcohol_percentage;
};

int Drink::get_nutrition_info() { return alcohol_percentage; };