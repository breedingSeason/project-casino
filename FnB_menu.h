#ifndef FNB_MENU_H
#define FNB_MENU_H
#include <string>
using namespace std;

class FnB_menu {
 protected:
  string name;
  int stock;  // quantity that are in store
  int price;

 public:
  FnB_menu();                                   // default constructor
  FnB_menu(string name, int stock, int price);  // constructor
  string get_name();                            // get name
  int get_price();                              // get price
  int get_stock();                              // get stock
  int update_stock();                           // decrease stock by 1
  int prepare_food(int x);  // update stock every time a food item is ordered, decrease the stock by input x
  void change_stock();  // ensures the ordered food is in stock and the stock is not negative, return true if stock>=0
  virtual int get_nutrition_info();  // will return different values based on derived class
};
#endif