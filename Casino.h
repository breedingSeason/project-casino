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
  Casino(); // default constructor
  void menu_casino(); // prints default list of options to chose from
  void set_food_menu(Employee emp1); // sets up the food menu 
  void set_betting_table(Employee emp1); // sets up the betting table 
  void module(Customer cust1, Employee emp1); // main function where all the calculation and user interaction takes place;
  void starting_module(); // the parimary function used to check if the user is eligible to play the game or not
  void starting_message(int x, Customer c1); // the starting message printed to the user
  void print_FnB_Menu(); // function to print the food and drinks available
  int validate_user_input(int input); // function to validate user inputs only numbers
  int user_age(); // int to prompt and user age
  string user_name(); // string to promt and store user name
  bool validate_name(string name); // function to validate user's name
  int validate_numbers(int x, int y, int z); // function to validate user input is within range of available options
  void customer_report(Customer cust1); // displays user related information to the
  
  ~Casino(); // def destructor 
};

#endif