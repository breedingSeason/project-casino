#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
 protected:
  string a_name;
  int a_age;

 public:
  Person(); // Default constructor
  Person(string name, int age); // Constructor with parameter of name and age
  string get_name(); // Get person's name
  int get_age(); // Get person's age
  virtual void give_response() = 0; // Pure virtual function
};

#endif