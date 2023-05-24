#include <iostream>
#include <string>
#include "Games.h"

using namespace std;

Games:: Games() {}

Games:: Games(int bet_amount, int num_players):
    game_number(0), bet_amount(bet_amount), player_won(false), 
    profits(0), loss(0), num_players(num_players) {}
    /*for(int i = 0; i < 18; i++) {
        cards[i] = (rand() % 7) + 8;
    }
    for(int i = 18; i < 36; i++) {
        cards[i] = (rand() % 13) + 2;
    }
    for(int i = 36; i < 52; i++) {
        cards[i] = (rand() % 5) + 2;
    } */


void Games:: set_bet(int x) {
    if(x < min_bet) {
    cout << "Invalid bet amount" << endl;
    }
    else {
        bet_amount = x;
    }
}

int Games:: get_bet() {
    return bet_amount;
}

int Games:: get_profit() {
    profit = get_bet();
    return profit;
}

int Games:: get_loss() {
    loss = get_bet();
    return loss;
}

void Games:: count_profit() {
    if(player_won == true) {
        profits+= profit;
    }
}

void Games:: count_loss() {
    if(player_won != true) {
        losses+= loss;
    }
}

int Games:: get_num_players() {
    return num_players;
}

int Games:: get_game_number() {
    return game_number;
}

void Games:: set_game_number() {
    game_number+= 1;
    
}

void Games:: set_num_players(int x) {}

bool Games:: won_game() {
    return true;
}

void Games:: get_card() {}

int Games:: get_max_players() {
    return 0;
}

int Games:: get_min_bet() {
    return min_bet;
}


