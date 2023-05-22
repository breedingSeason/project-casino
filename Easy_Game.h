#ifndef EASY_GAME_H
#define EASY_GAME_H

#include <iostream>
#include "Games.h"
using namespace std;

class Easy_Game: public Games{
    private:
        int cards[3];
        const int max_bet = 100000;
        int max_games_played = 5;
        int max_players = 3;
        int Player_cards_Sum;
    public:
        Easy_Game();
        Easy_Game(int bet_amount, int min_bet, int num_players);
        int get_max_players() override; // returns the maximum number of players allowed
        void get_card() override;
        void set_num_players(int x) override;
        bool won_game() override;
};

#endif

