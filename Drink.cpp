#include <string>
#include <iostream>
#include "Drink.h"
Drink::Drink():FnB_menu(),alcohol_percentage(0),drink_type(""){};

Drink::Drink(string name,int stock, int price, string type, int alcohol_percentage,string drink_type):FnB_menu(name, stock, price, type),alcohol_percentage(alcohol_percentage),drink_type(drink_type){};

int Drink::get_nutrition_info(){
    return this->alcohol_percentage;
};

bool Drink::isAlcohol(){
    return (drink_type == "Alcohol");
};