#include <iostream>
#include <string>
using namespace std;
#include "Juice.h"

Juice::Juice():Drink(),calories(0){};
Juice::Juice(string name,int stock, int price, string type, int calories):Drink(string name,int stock, int price, string type, 0,"Juice"),calories(calories){};
int Juice::get_nutrition_info(){
    return this->calories;
};