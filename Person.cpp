#include "Person.h"

#include <iostream>
using namespace std;

Person::Person() {}

Person::Person(string name, int age) {
  a_name = name;
  a_age = age;
}

string Person::get_name() { return a_name; }

int Person::get_age() { return a_age; }

