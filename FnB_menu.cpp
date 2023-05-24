#include<iostream>
#include<string>
#include "FnB_menu.h"
using namespace std;

FnB_menu::FnB_menu():name(""),stock(0),price(0){};

FnB_menu::FnB_menu(string name,int stock, int price, string type):name(name),stock(stock),price(price), type_food(type){};

string FnB_menu::get_name(){
    return name;
};
int FnB_menu::get_price(){
    return price;
};

int FnB_menu::get_stock(){
    return stock;
};

int FnB_menu:: get_type() {
    int choice = 0;
    if(type_food == "Drinks") {
        choice = 1;
    }
    else if (type_food == "Snacks"){
        choice = -1;
    }
    else {
        choice = 0;
    }
    return choice;
}

int FnB_menu::prepare_food(){//update stock every time a food item is ordered
    int stock=get_stock();
    stock-=1;
    this->stock=stock;
    return stock;
};

bool FnB_menu::change_stock(){//if stocks>0,return true
if(stock < 0) {
    stock = 0;
}
    return stock;
};

int FnB_menu::get_nutrition_info(){
    return 0;
};

string FnB_menu:: get_flavour() {
    return 0;
}

FnB_menu:: ~FnB_menu() {};