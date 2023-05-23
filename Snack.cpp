#include <string>
#include <iostream>
#include "Snack.h"

Snacks:: Snacks() {};

Snacks:: Snacks(string name,int stock, int price, string type, int calories, string flavour): Food(name, stock, price, type, calories), flavour(flavour) {};

string Snacks:: get_flavour() { return flavour; }