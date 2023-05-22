#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

#include "Person.h"
using namespace std;

class Customer : public Person {
 private:
  const int drunkness_max = 100;
  int drunkness = 0;
  int wallet = 150000;
  const int min_money = 0;
  int hungriness = 80;
  int games_played = 0;
  string conscious_rep[5];
  string tipsy_rep[5];

 public:
  Customer();  // Default constructor
  Customer(string name, int age);
  int order_food(int price);
  int place_bet(int x);
  int get_games_played();
  int drink(int x);
  int get_drunkness();
  int eat(int x);
  int get_hungriness();
  int money_left();
  void give_response() override;
};

#endif