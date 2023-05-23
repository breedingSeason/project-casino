#ifndef FOOD_H
#define FOOD_H
#include <string>
#include "FnB_menu.h"
using namespace std;
class Food: public FnB_menu{
    private:
    int calories;
    public:
    Food();//default cons
    Food(string name,int stock, int price, string type, int calories);//cons
    int get_nutrition_info() override; //returns number of calories
};
#endif