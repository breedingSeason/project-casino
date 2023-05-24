#include<iostream>
#include <string>
#include "FnB_menu.cpp"
#include "Person.cpp"
#include "Customer.cpp"
#include "Games.cpp"
#include "Easy_Game.cpp"
#include "Hard_Game.cpp"
using namespace std;

class UnitTest{
    protected:
    void testFnB(){
        FnB_menu coke("Coke",2,5,"Drinks");
        if(coke.get_name()!="Coke"){
            cout<<"Name error!"<<endl;
        }
        if(coke.get_price()!=5){
            cout<<"Price error!"<<endl;
        }
        if(coke.get_stock()!=2){
            cout<<"Stock error!"<<endl;
        }
        if(coke.prepare_food()!=1){
            cout<<"Prepare food false!"<<endl;
        }
        coke.prepare_food();
        if(coke.change_stock()==true){
            cout<<"Change stock false!"<<endl;
        }
    }
    void testPerson(){
        Customer Customer("Ryan",28);
        if(Customer.order_drink(5000)!=145000){
            cout<<"Order drink false!"<<endl;
        }
        if(Customer.get_games_played()!=0){
            cout<<"Init games false!"<<endl;
        }
        Customer.set_games_played();
        if(Customer.get_games_played()!=1){
            cout<<"Set games false!"<<endl;
        }
        if(Customer.drunk_percentage(10)!=10){
            cout<<"Drunk increase false!"<<endl;
        }
        if(Customer.update_wallet(5000)!=150000){
            cout<<"Update wallet false!"<<endl;
        }
    }
    void testGames(){
        //test atrributes in Games, but Games has virtual functions so use its inherit class here
        Easy_Game AGame(2000,5);
        if(AGame.get_min_bet()!=1000){
            cout<<"Init min bet false!"<<endl;
        }
        if(AGame.get_game_number()!=0){
            cout<<"Init game number false!"<<endl;
        }
        AGame.set_game_number();
        if(AGame.get_game_number()!=1){
            cout<<"Set game number false!"<<endl;
        }
        if(AGame.get_bet()!=2000){
            cout<<"Bet get false!"<<endl;
        }
        //test the inherit class Easy_Game and the override functions
        Easy_Game GameE(1500,3);
        cout<<"Expected: Please choose lower number of players."<<endl;
        cout<<"Test:";
        GameE.set_num_players(5);
        //test the inherit class Hard_Game
        Hard_Game GameH(3000,5);
        if(GameH.get_max_players()!=4){
            cout<<"Init min player false!"<<endl;
        }
        GameH.get_card();
        if(GameH.won_game()==true){
            //cout<<"Win game pass!"<<endl;
        }
        else if(GameH.won_game()==false){
            
        }
        else cout<<"Win test false!"<<endl;
    }
    public:
    void runtest(){
        testFnB();
        cout<<"FnB test ended."<<endl;
        testPerson();
        cout<<"Person test ended."<<endl;
        testGames();
        cout<<"Games test ended"<<endl;
    }
};