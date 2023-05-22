#include "Casino.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Casino:: Casino() {}

void Casino::set_food_menu(Employee employee) {
    string food_file = "Food_Menu.csv";
    std::ifstream file(food_file);
    if (food_file.is_open()) {
        string lines;
        num_food = 0;
        while(std::getline(food_file, lines)) {
            num_food++;
        }
        food_file.clear();
        food_file.seekg(0);

        food_menu = new FnB_Menu*[num_food];

        for(int i = 0; std::getline(food_file, lines); i++) {
            if(lines.empty()) {
                continue;
            }
            string row;
            string columns[5]
            std:: stringstream str(lines);
            for(int j = 0; std::getline(str, row, ','); j++) {
                columns[i] = row;
            }
            if(columns[4] == "Drinks"){
				food_menu[i] = new Drink(columns[0], std::stoi(columns[1]), std::stoi(columns[2]), columns[3], std::stoi(columns[4])); 
			}else if(columns[4] == "Snacks"){
				food_menu[i] = new Food(columns[0], std::stoi(columns[1]), std::stoi(columns[2]), columns[3],  std::stoi(columns[4]));
			}
        }
    }
    else {
        cout << "Can't open file." << endl;
    }
}

void Casino:: main_window() {
    cout << "Choose from the following list of actions: " << endl;
    cout << "0. Leave :(     |   1. $$Gamble     |   2. Eat :))     )" << endl;
}

void Casino::set_betting_table(Employee employee) {
    
}

void Casino::main_module(Customer customer, Employee employee) {
    int user_input;
    cout << "Your wallet has $" << customer.money_left() << ". Have fun out there!" << endl;
    main_window();
    cin >> user_input;

    user_input = validate_user_input(user_input);


    set_food_menu(employee);

    while(user_input == 0 || user_input == 1 || user_input == 2) {
        if(user_input == 0) {
            cout << "Thanks for giving us all your money. See you again!"
            break;
        }
        else if(user_input == 2) {
            int food_choice;
            print_FnB_Menu();

            cin >> food_choice;
            food_choice = validate_user_input(food_choice);

            while(food_choice >= 0 || food_choice <=num_food) {
                if(food_choice == 0) {
                    break;
                }
                else{
                    food_menu[food_choice - 1]->prepare_food();
                    if(food_menu[food_choice-1]->get_stock() > 0) {
                        customer.order_food(food_menu[food_choice-1]->get_price);
                        if(customer.get_type() != 0) {
                            customer.drink(food_menu[food_choice-1]->get_nutrition_info());
                        }
                        else {
                            customer.eat(food_menu[food_choice-1]->get_nutrition_info());
                        }
                        customer.give_response();
                        employee.greet(customer.get_drunkness());
                        break;
                    } else {
                        cout << "I'm sorry but we ran out of " << food_menu[food_choice-1]->get_name() << "Maybe another day." << endl;
                        food_menu[food_choice-1]->change_stock;
                    }
                    break;

                    }
                }
            }
            else if (user_input == 1) {
                
            }
        }
    }
    
}

void Casino::starting_module() {
    
}

void Casino::starting_message(int x, Customer customer) {
    
    
}

        void Casino::print_FnB_Menu() {
            for(int i = 0; i < num_food; i++) {
                cout << i+1 << food_menu[i].get_name() << " | $" << food_menu[i].get_price << " | " << food_menu[i].get_stock << " drinks left" 
            }
            cout << "Let us know what you want by typing in the corresponding item number: " << endl;
        }

        int Casino::validate_user_input(int input) {
            while(cin.fail()) { //!cin
                cout << "What you doing? Type in valid numbers only: "l
                cin.clear();
                cin.ignore(sizeof(int), '\n');
                cin >> input;
            }
            return input;
        }


        int Casino::user_age() {
            int age;
            cout << "Please enter your age: " << endl;
            cin >> age;

            while(age < 1 or age > 99) {
                cout << "That's not a reasonable answer: " << endl;
                cin >> age;
                age = this-> validate_user_input(age);
            }
            return age;
        }
        string Casino::user_name() {
            string name;
            cout << "What is your name? " << endl;
            cin >> name;

            while(validate_name() == 0) {
                cout << "Thats not a real name. Try again: " << endl;
                cin >> name;
            }
            return name;
        }

        bool Casino::validate_name(string name) {
            bool valid = false; 

            for(int i = 0; i < name.length(); i++) {
                if((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) || name[i] == 32) {
                    valid = true;
                }
                else {
                    valid = false;
                }
            }
            return valid;
        }
