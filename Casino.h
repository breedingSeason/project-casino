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
  FnB_menu** food_menu;
  Games** bet_counter;
  int num_games = 0;
  const int max_num_games = 15;
  int num_food;
  
 public:
  Casino();
  void menu_casino();
  void set_food_menu(Employee emp1);
  void set_betting_table(Employee emp1);
  void module(Customer cust1, Employee emp1);
  void starting_module();
  void starting_message(int x, Customer c1);
  void print_FnB_Menu();
  int validate_user_input(int input);
  int user_age();
  string user_name();
  bool validate_name(string name);
  int validate_numbers(int x, int y, int z);
  void customer_report(Customer cust1);
  
  ~Casino();
};

#endif