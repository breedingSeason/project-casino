#include <string>
#include <iostream>
#include "Food.h"
Food::Food():FnB_menu(),calories(0){};

Food::Food(string name,int stock, int price,int calories):FnB_menu(string name, int stock, int price),calories(this->calories){};

int Food::get_nutrition_info(){
    return this->calories;
};
