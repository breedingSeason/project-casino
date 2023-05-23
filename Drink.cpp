#include <string>
#include <iostream>
#include "Drink.h"
Drink::Drink():FnB_menu(),alcohol_percentage(0){};

Drink::Drink(string name,int stock, int price, string type, int alcohol_percentage):FnB_menu(name, stock, price, type),alcohol_percentage(alcohol_percentage){};

int Drink::get_nutrition_info(){
    return this->alcohol_percentage;
};