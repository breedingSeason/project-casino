#include "Customer.h"

#include <iostream>

using namespace std;

Customer::Customer(string name, int age) : Person(name_, age_) {
  conscious_rep[0] = "Customer: This is lovely";
  conscious_rep[1] = "Customer: What a day";
  conscious_rep[2] = "Customer: Seriously, I think I should stop drinking";
  conscious_rep[3] = "Customer: Today is awesome, right?";
  conscious_rep[4] = "Customer: You are so handsome";

  tipsy_rep[0] = "Customer: PLEASE LET ME GOO!!";
  tipsy_rep[1] = "Customer: MAMA, COME PICK ME UP!!!";
  tipsy_rep[2] = "Customer: Is this me? LMAO";
  tipsy_rep[3] = "Customer: Bro, do you think I'm cute? *do backflip*";
  tipsy_rep[4] = "Customer: *Suddenly starts running*";
}

int Customer::order_drink(int price) {
  wallet = wallet - price;
  if (wallet < min_money) {
    wallet = wallet + price;
    cout << "Bartender: I think you already run out of money hahaha" << endl;
    return wallet;
  } else {
    cout << "Bartender: Here you go!" << endl;
    return wallet;
  }
}

int Customer::order_food(int price) {
  wallet = wallet - price;
  if (wallet < min_money) {
    wallet = wallet + price;
    cout << "Bartender: I think you already run out of money hahaha" << endl;
    return wallet;
  } else {
    cout << "Bartender: Here you go!" << endl;
    return wallet;
  }
}

int Customer::place_bet(int x) {
  // Increase games played
  games_played = games_played + x;
  if (games_played > 0) {
    return games_played;
  } else if (games_played < 0) {
    games_played = 0;
    cout << "Play more! You will win next time for sure!" << endl;
    return games_played;
  } else {
    return games_played;
  }
}

int Customer::drunk_percentage(int x) {
  // Increase drunkness
  drunkness = drunkness + x;
  if (drunkness > drunkness_max) {
    return drunkness;
  } else if (drunkness < 0) {
    drunkness = 0;
    cout << "Drink more, mate!" << endl;
    return drunkness;
  } else {
    return drunkness;
  }
}

int Customer::hunger_percentage(int x) {
  // Increase hungriness
  hungriness = hungriness - x;
  if (hungriness < 80 and hungriness > 0) {
    return hungriness;
  } else if (hungriness <= 0) {
    hungriness = 0;
    cout << "Customer: I feel like vomiting..." << endl;
    return hungriness;
  } else {
    return hungriness;
  }
}

int Customer::get_drunkness() { return drunkenness; }

int Customer::get_hungriness() { return hungriness; }

int Customer::get_games_played() { return games_played; }

int Customer::money_left() { return wallet; }

void Customer::give_response() override {
  // give response based on drunkness
  if (drunkness >= 50 && drunkness < drunkness_max) {
    cout << tipsy_rep[(rand() % 5)] << endl;
  } else if (drunkness >= 0 && drunkness < 50) {
    cout << conscious_rep[(rand() % 5)] << endl;
  } else if (drunkness >= drunkness_max) {
    cout << "Customer: Is this my bed? *starts lying on the floor*" << endl;
  } else {
    cout << tipsy_rep[(rand() % 5)] << endl;
  }
}