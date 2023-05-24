#ifndef JUICE_H
#define JUICE_H

#include "Drink.h"
#include <string>
class Juice: public Drink{
    private:
    int calories;
    public:
    Juice();
    Juice(string name,int stock, int price, string type, int calories);
    int get_nutrition_info() override; //returns number of calories
};

#endif