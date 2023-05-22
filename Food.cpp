#include <string>
#include <iostream>
#include "Food.h"
Food::Food():FnB_menu(),calories(0){};

Food::Food(string name,int stock, int price,int calories, string type):FnB_menu(string name, int stock, int price, string type),calories(calories){};

int Food::get_nutrition_info(){
    return this->calories;
};
