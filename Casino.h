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

 public:
  Casino(); // Default constructor
  void menu_casino(); // A written message that customers can respond to
  void set_food_menu(Employee emp1); // Allows the employee to prepare the foods and drinks menu. Food_menu.csv is the database
  void set_betting_table(Employee emp1); // 
  void module(Customer cust1, Employee emp1); // The parameter will receive a customer and an employee, where all primary calculations and interaction takes place
  void starting_module(); // Enables encapsulation of the main code
  void starting_message(int x, Customer c1); // An opening statement at the start of the programme
  void print_food_Menu(); // Print out the list of drinks and foods
  int validate_user_input(int input); // Ensure that the user's input is limited to integers
  int user_age(); // Ask the user's age
  string user_name(); // Asks the user's name
  bool validate_name(string name); // Ensure the user's name is valid
  int validate_numbers(int x, int y, int z); // Ensure the user's input is within range
  void customer_report(); // Important informations/reports about the customer 
  ~Casino(); // Destructor to delete the food_menu array
};

#endif