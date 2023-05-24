#ifndef SNACK_H
#define SNACK_H

#include <string>

#include "Food.h"

using namespace std;

class Snacks : public Food {
 private:
  string flavour;

 public:
  Snacks();  // Default constructor
  Snacks(string name, int stock, int price, string type, int calories, string flavour); // Parameterized constructor
  string get_flavour() override;  // Returns flavour
};

#endif