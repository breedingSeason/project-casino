#ifndef DRINK_H
#define DRINK_H
#include <string>
#include "FnB_menu.h"
using namespace std;
class Drink: public FnB_menu{
    private:
    int alcohol_percentage;
    public:
    Drink();//default cons
    Drink(string name,int stock, int price, string type, int alcohol_percentage);//cons
    int get_nutrition_info() override; //returns number of alcohol percentage
};
#endif