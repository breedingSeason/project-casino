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
  Customer(string name,
           int age);           // Constructor with parameters for name and age
  int order_drink(int price);  // Deduct the customer's money in accordance with
                               // the cost of the drinks they purchase
  int order_food(int price);   // Deduct the customer's money in accordance with
                               // the cost of the foods they purchase
  int place_bet(int x);        // Change the value of games_played
  int get_games_played();      // Return games_played
  int drunk_percentage(int x);    // Change the value of drunkness
  int get_drunkness();            // Return drunkness
  int hunger_percentage(int x);   // Change the value of hungriness
  int get_hungriness();           // Return hungriness
  int money_left();               // Return wallet
  void give_response() override;  // Give response according to the situations
};

#endif