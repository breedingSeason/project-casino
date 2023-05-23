#include <string>
#include <iostream>
#include "Food.h"


Food::Food():FnB_menu(),calories(0){};

Food::Food(string name,int stock, int price, string type, int calories):FnB_menu(name, stock, price, type),calories(calories){};

int Food::get_nutrition_info(){
    return this->calories;
};
