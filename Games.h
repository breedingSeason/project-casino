#ifndef GAMES_H
#define GAMES_H

#include <iostream>
using namespace std;

class Games{
    protected:
        int game_number;
        int bet_amount;
        const int min_bet = 1000;
        bool player_won;
        int profits;
        int profit;
        int losses;
        int loss;
        int num_players;
        //int cards[52];
    public:
        Games();
        Games(int bet_amount, int num_players);
        void set_bet(int x);
        int get_profit();
        int get_loss();
        void count_profit();
        void count_loss();
        int get_num_players();
        int get_game_number();
        void set_game_number();
        virtual void set_num_players(int x);
        virtual bool won_game() = 0;
        virtual void get_card() = 0;
        virtual int get_max_players() = 0;
        int get_min_bet();
        int get_bet();
};

#endif