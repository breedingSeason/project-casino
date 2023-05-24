#ifndef HARD_GAME_H
#define HARD_GAME_H

#include <iostream>

#include "Games.h"
using namespace std;

class Hard_Game : public Games {
 private:
  int cards[5];
  int min_games_played = 4;
  int min_players = 4;
  int Player_cards_Sum;

 public:
  Hard_Game(); // Default constructor
  Hard_Game(int bet_amount, int num_players); // Parameterized constructor
  int get_max_players() override; // // Returns the maximum number of players allowed
  void get_card() override; // Get card
  void set_num_players(int x) override; // Set number of players
  bool won_game() override; // Return true if the player win the game
};

#endif