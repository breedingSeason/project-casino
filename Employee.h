#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

#include "Person.h"
using namespace std;

class Employee : public Person {
 private:
  string conscious_rep[5];
  string tipsy_rep[5];

 public:
  Employee(); // Default constructor
  Employee(string name, int age); // Constructor with parameters for name and age
  void greet() override; // Override virtual function from person class
  void greet(int drunkness); // Enables the employee to communicate with the customers depending on the drunkness
};

#endif