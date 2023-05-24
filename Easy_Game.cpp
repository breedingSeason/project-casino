#include "Easy_Game.h"


Easy_Game:: Easy_Game(int bet_amount, int num_players): Games(bet_amount, num_players) {}
    //for(int i = 0; i < 20; i++) {
      //  Player_cards[i] = cards[i];
    //}


int Easy_Game:: get_max_players() {
    return max_players;
} 

void Easy_Game:: get_card() {
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        cards[i] = (rand() % 7) + 8;
        sum+= cards[i]; 
        cout << cards[i] << endl;
    }
    Player_cards_Sum = sum;
    cout << "sum: " << sum << endl;
}

void Easy_Game:: set_num_players(int x) {
    if(x <= max_players) {
        num_players = x;
    }
    else {
        cout << "Please choose lower number of players." << endl;
    }
}

bool Easy_Game:: won_game() {
    bool won = true;
    int x = (rand() %6) + 15;
    int y = (rand() %11) + 20;
    cout << x << endl;
    cout << y << endl;

    if(Player_cards_Sum <= x && Player_cards_Sum <= y) {
        won = false;
    }
    return won;
}