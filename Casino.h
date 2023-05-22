#ifndef CASINO_H
#define CASINO_H

#include <iostream>

#include "Customer.h"
#include "Drink.h"
#include "Easy_Game.h"
#include "Employee.h"
#include "Food.h"
#include "Hard_Game.h"

using namespace std;

class Casino {
  FnB_Menu** food_menu;
  Games** bet_counter;
  int num_games;
  int num_food;
  int num_drink;

 public:
  Casino();
  void menu_casino();
  void set_food_menu(Employee emp1);
  void set_betting_table(Employee emp1);
  void module(Customer cust1, Employee emp1);
  void starting_module();
  void starting_message(int x, Customer c1);
  void print_food_Menu();
  void print_drink_Menu();
  int validate_user_input(int input);
  int user_age();
  bool validate_age(int x);  // this is not needed?
  string user_name();
  bool validate_name(string name);
  int validate_numbers(int x, int y, int z);
  void customer_report();
  ~Casino();
};

#endif