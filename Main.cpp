#include <ctime>
#include <iostream>

#include "Casino.h"
#include "Customer.h"
#include "Employee.h"
#include "FnB_menu.h"
#include "Games.h"
#include "Person.h"

int main() {
  srand(time(NULL));           // To get a random index for responses
  Casino* start = new Casino;  // Make a new object start
  start->starting_module();    // Start the program

  delete start;
}