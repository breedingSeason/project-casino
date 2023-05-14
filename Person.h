#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
 protected:
  string a_name;
  int a_age;

 public:
  Person();
  Person(string name, int age);
  string get_name();
  int get_age();
};

#endif