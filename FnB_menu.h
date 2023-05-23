#ifndef FNB_MENU_H
#define FNB_MENU_H
#include <string>
using namespace std;

class FnB_menu {
 protected:
  string name;
  int stock;  // quantity that are in store
  int price;
  string type_food;

 public:
  FnB_menu();                                   // Default constructor
  FnB_menu(string name, int stock, int price, string type);  // Parameterized constructor
  string get_name();                            // Get name
  int get_price();                              // Get price
  int get_stock();                              // Get stock
  int get_type();                               // Get type of FnB
  int prepare_food();  // Update stock every time a food item is ordered
  void change_stock();  // Ensures the ordered food is in stock and the stock is not negative, return true if stock>=0
  virtual int get_nutrition_info();  // Will return different values based on derived class
};
#endif