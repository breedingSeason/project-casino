#include <string>
#include <iostream>
#include "Drink.h"
Drink::Drink():FnB_menu(),alcohol_percentage(0){};

Drink::Drink(string name,int stock, int price,int alchol_percentage):FnB_menu(string name, int stock, int price),alchol_percentage(this->alcohol_percentage){};

int Drink::get_nutrition_info(){
    return this->alcohol_percentage;
};