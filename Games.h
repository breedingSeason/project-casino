#ifndef GAMES_H
#define GAMES_H

#include <iostream>
#include <vector>
using namespace std;

class Games {
 protected:
  int game_number;
  int bet_amount;
  const int min_bet = 25000;
  bool player_won;
  int profits;
  int profit;
  int losses;
  int loss;
  int num_players;
  vector<int> user_scores;
  // int cards[52];

 public:
  Games();                                 // Default constructors
  Games(int bet_amount, int num_players);  // Parameterized constructor
  void set_bet(int x);                     // Set the bet
  int get_profit();                        // Return profit
  int get_loss();                          // Return loss
  void count_profit();                     // Change the value of profit
  void count_loss();                       // Change the value of loss
  int get_num_players();                   // Return number of players
  int get_game_number();                   // Return number of games
  void set_game_number();                  // Increment number of games by 1
  virtual void set_num_players(
      int x);  // Set number of players by taking x as the parameter
  virtual bool won_game() = 0;  // Pure virtual function for derived classes
  virtual void get_card() = 0;  // Pure virtual function for derived classes
  virtual int
  get_max_players() = 0;  // Pure virtual function for derived classes
  int get_min_bet();      // Return minimum of bet
  int get_bet();          // Return bet
  void print_scores();    // Prints the user scores
  virtual ~Games();       // Virtual destructor
};

#endif