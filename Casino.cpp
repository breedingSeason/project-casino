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
				food_menu[i] = new Drink(columns[0], std::stoi(columns[1]), std::stoi(columns[2]), std::stoi(columns[3])); 
			}else if(columns[5] == "Snacks"){
				food_menu[i] = new Food(columns[0], std::stoi(columns[1]), std::stoi(columns[2]), std::stoi(columns[3]));
			}
        }
    }
    else {
        cout << "Can't open file." << endl;
    }
}

void Casino::set_betting_table(Employee employee) {
    
}

void Casino::main_module(Customer customer, Employee employee) {
    
}

void Casino::starting_module() {
    
}

void Casino::starting_message(int x, Customer customer) {
    if (x == 1)
    
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
