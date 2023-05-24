#ifndef SNACK_H
#define SNACK_H

#include <string>
#include "Food.h"

using namespace std;

class Snacks: public Food {
    private:
        string flavour;
    public:
    Snacks(); // default constructor
    Snacks(string name,int stock, int price, string type, int calories, string flavour); // 
    string get_flavour() override; // returns the flavour
};

#endif