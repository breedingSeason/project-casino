#include "Hard_Game.h"

HardGame:: HardGame(int bet_amount, int num_players): Games(bet_amount, num_players){}
    //for(int i = 0; i < 20; i++) {
      //  Player_cards[i] = cards[i];
    //}


int HardGame:: get_max_players() {
    return min_players;
} 

void HardGame:: get_card() {
    int sum = 0;
    if(game_number > min_games_played) {
        for(int i = 0; i < 5; i++) {
            cards[i] = (rand() % 13) + 3;
            sum+= cards[i]; 
        }
        Player_cards_Sum = sum;
    } 
}

void HardGame:: set_num_players(int x) {
    if(x >= min_players) {
        num_players = x;
    }
    else {
        cout << "Please choose higher number of players." << endl;
    }
}

bool HardGame:: won_game() {
    bool won = true;
    int x[5];

    for(int i = 0; i < 4; i++) {
        x[i] = (rand() % 20) + 45;
        if(Player_cards_Sum <= x[i]) {
            won = false;
        }
    }
    return won;
}