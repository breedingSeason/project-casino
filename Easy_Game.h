#ifndef EASY_GAME_H
#define EASY_GAME_H

#include <iostream>

#include "Games.h"
using namespace std;

class Easy_Game : public Games {
 private:
  int cards[3];
  int max_games_played = 5;
  int max_players = 3;
  int Player_cards_Sum;

 public:
  Easy_Game();                                 // Default constructors
  Easy_Game(int bet_amount, int num_players);  // Parameterized constructors
  int get_max_players()
      override;              // Returns the maximum number of players allowed
  void get_card() override;  // Get card
  void set_num_players(int x) override;  // Set number of players
  bool won_game() override;  // Return true if the player win the game
};

#endif
