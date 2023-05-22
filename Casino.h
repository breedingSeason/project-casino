#ifndef CASINO_H
#define CASINO_H

#include<iostream>
#include "Hard_Game.h"
#include "Easy_Game.h"
#include "Customer.h"
#include "Employee.h"
#include "Food.h"
#include "Drink.h"

using namespace std;

class Casino{

    FnB_Menu** food_menu;
    Games** bet_counter;
    int num_games;
    int num_food;
    

    public:
        Casino();
        void set_food_menu(Employee e);
        void set_betting_table(Employee e);
        void main_module(Customer c, Employee e);
        void main_window(); // provide the main list of options to the user i.e. gamble, eat or leave
        void starting_module();
        void starting_message(int x, Customer c);
        void print_FnB_Menu();
        int validate_user_input(int input);
        int user_age();
        bool validate_age(int x);
        string user_name();
        bool validate_name(string name);

        ~Casino();
};



#endif