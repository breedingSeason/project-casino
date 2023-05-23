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
  Employee();
  Employee(string name, int age);
  void give_response() override;
  void give_response(int drunkness);
};

#endif