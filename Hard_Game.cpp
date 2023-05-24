#include "Hard_Game.h"

Hard_Game:: Hard_Game(int bet_amount, int num_players): Games(bet_amount, num_players){}
    //for(int i = 0; i < 20; i++) {
      //  Player_cards[i] = cards[i];
    //}


int Hard_Game:: get_max_players() {
    return min_players;
} 

void Hard_Game:: get_card() {
    int sum = 0;
    if(game_number > min_games_played) {
        for(int i = 0; i < 5; i++) {
            cards[i] = (rand() % 11) + 40;
            sum+= cards[i]; 
            cout << "Your cards number " << i+1 <<": " << cards[i] << endl;
        }
        Player_cards_Sum = sum;
        user_scores.push_back(sum);
        cout << "The sum of your cards is: " << sum << endl;
    } 
    
}

void Hard_Game:: set_num_players(int x) {
    if(x >= min_players) {
        num_players = x;
    }
    else {
        cout << "Please choose higher number of players." << endl;
    }
}

bool Hard_Game:: won_game() {
    bool won = true;
    int x[5];

    for(int i = 0; i < 4; i++) {
        x[i] = (rand() % 10) + 55;
        cout << "Opponent " << i << "'s sum of cards: " << x[i] << endl;
        if(Player_cards_Sum <= x[i]) {
            won = false;
        }
    }
    return won;
}