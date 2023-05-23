#ifndef HARD_GAME_H
#define HARD_GAME_H

#include <iostream>
#include "Games.h"
using namespace std;

class HardGame: public Games {
    private:
        int cards[5];
        int min_games_played = 4;
        int min_players = 4;
        int Player_cards_Sum;
    public:
        HardGame();
        HardGame(int bet_amount, int num_players);
        int get_max_players() override;
        void get_card() override;
        void set_num_players(int x) override;
        bool won_game() override;
};

#endif