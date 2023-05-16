#include "Employee.h"

#include <iostream>

using namespace std;

Employee::Employee(string name, int age) : Person(name, age) {
  conscious_rep[0] = "Employee: *Wink*";
  conscious_rep[1] = "Employee: *Smile*";
  conscious_rep[2] = "Employee: Yeah";
  conscious_rep[3] = "Employee: Are you single?";
  conscious_rep[4] = "Employee: Hahaha exactly";

  tipsy_rep[0] = "Employee: OMG, are you okay?";
  tipsy_rep[1] = "Employee: Papi, aren't you tipsy?";
  tipsy_rep[2] = "Employee: Keep drinking hahaha";
  tipsy_rep[3] = "Employee: Lemme lick ur feet";
  tipsy_rep[4] = "Employee: Maybe you should stop now";
}

void Employee::greet() override {
  cout << "Employee: Hellower!! G'day,mate?" << endl;
}

void Employee::greet(int drunkness) {
  if (drunkness >= 50 and drunkness < 100) {
    cout << tipsy_rep[(rand() % 5)] << endl;
  } else if (drunkness >= 0 and drunkness < 75) {
    cout << conscious_rep[(rand() % 5)] << endl;
  } else if (drunkness >= 100) {
    cout << "Employee: Okay, shawty. It's time for you to go home *pick "
            "customer up*"
         << endl;
  }
}