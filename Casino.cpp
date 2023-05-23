#include "Casino.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

Casino::Casino() {}

void Casino::menu_casino() {
  cout << "Choose from the following list of actions: " << endl;
  cout << "0. Leave :(     |   1. Eat :))     |   2. $$Gamble     " << endl;
}

void Casino::set_betting_table(Employee emp1) {
  bet_counter = new Games*[max_num_games]; // 
  cout << "Welcome to our world of gambling" << endl; 
  cout << "Please input how much money you want to bet: " << endl;
}

void Casino::set_food_menu(Employee emp1) {
  string food_file = "Food_Menu.csv";
std::ifstream file(food_file);

if (file.is_open()) {
  string lines;
  num_food = 0;

  while (std::getline(file, lines)) {
    num_food++;
  }

  file.clear();
  file.seekg(0);

  food_menu = new FnB_menu*[num_food];

  for (int i = 0; std::getline(file, lines); i++) {
    if (lines.empty()) {
      continue;
    }

    string row;
    string columns[5];
    stringstream str(lines);

    for (int j = 0; std::getline(str, row, ','); j++) {
      columns[j] = row;
    }

    if (columns[3] == "Drinks") {
      food_menu[i] = new Drink(columns[0], std::stoi(columns[1]),
                                std::stoi(columns[2]), columns[3], std::stoi(columns[4]));
    } else if (columns[3] == "Snacks") {
      food_menu[i] = new Food(columns[0], std::stoi(columns[1]),
                              std::stoi(columns[2]), columns[3], std::stoi(columns[4]));
    }
  }

  file.close();
} else {
  cout << "Can't open file." << endl;
}
}

void Casino::module(Customer cust1, Employee emp1) {
  // This the main module, every major calculation and user interaction happens
  // here
  int choice;
  cout << "You have $" << cust1.money_left() << endl;
  cout << "Your drunk level is " << cust1.get_drunkness() << "." << endl;
  cout << "Your number of games played is " << cust1.get_games_played() << "." << endl;

  this->menu_casino();
  cin >> choice;
  choice = this->validate_user_input(choice);
  choice = this->validate_numbers(0, 3, choice);

  this->set_food_menu(emp1);

  while (choice == 1 || choice == 2 || choice == 0) {
    if (choice == 1) {  // eat and drink
      int cust_resp;
      cout << endl;

      this->print_FnB_Menu();
      cin >> cust_resp;
      cout << endl;

      cust_resp = this->validate_user_input(cust_resp);
      cust_resp = this->validate_numbers(0, num_food, cust_resp);

      while (cust_resp >= 0 || cust_resp <= num_food) {
        if (cust_resp == 0) {
          break;
        } else {
          food_menu[cust_resp - 1]->prepare_food();
          if (food_menu[cust_resp - 1]->get_stock() >= 0) {
            cust1.order_drink(food_menu[cust_resp - 1]->get_price());
            cust1.drunk_percentage(
                food_menu[cust_resp - 1]->get_nutrition_info());
            cust1.give_response();
            emp1.give_response(cust1.get_drunkness());
            break;
          } else {
            cout << "Bartender: Unfortunately, we just ran out of "
                 << food_menu[cust_resp - 1]->get_name() << endl;
            food_menu[cust_resp - 1]->change_stock();
          }
          break;
        }
      }

    } else if (choice == 0) {
      cout << "Bye. Hope you enjoy your night here ^^" << endl;
      break;

    } else if (choice == 2) {  // gamble
      int cust_resp;
      cout << endl;

      this->set_betting_table(emp1);
      cin >> cust_resp; 

      cust_resp = this->validate_user_input(cust_resp);
      cust_resp = this->validate_numbers(1000, cust1.money_left(), cust_resp);

      while (cust_resp >= 0 && cust_resp <= cust1.money_left()) {
        if(cust_resp == 0) {
          break;
        }
        else{
          while(num_games < 5) {
            bet_counter[num_games] = new Easy_Game(cust_resp, 3);
            bet_counter[num_games]->get_card();
            if(bet_counter[num_games]->won_game()) {
              cust1.update_wallet(bet_counter[num_games]->get_profit());
              bet_counter[num_games]->count_profit();
              cout << "Congrats!! You won " << cust_resp << " Dollars!" << endl;
            }
            else {
              cust1.update_wallet(-(bet_counter[num_games]->get_loss()));
              bet_counter[num_games]->count_loss();
              cout << "Unfortunately you lost the bet :( " << endl;
            }
            cust1.place_bet(1);
            num_games++;
            break;
          }
          if(num_games > 5 && num_games <= max_num_games) {
            bet_counter[num_games] = new Hard_Game(cust_resp, 5);
            bet_counter[num_games]->get_card();
            if(bet_counter[num_games]->won_game()) {
              cust1.update_wallet(bet_counter[num_games]->get_profit());
              bet_counter[num_games]->count_profit();
              cout << "Congrats!! You won " << cust_resp << " Dollars!" << endl;
            }
            else {
              cust1.update_wallet(-(bet_counter[num_games]->get_loss()));
              bet_counter[num_games]->count_loss();
              cout << "Unfortunately you lost the bet :( " << endl;
            }
            cust1.place_bet(1);
            num_games++;
            break;
          }
          else if (num_games > max_num_games){
            cout << "You have already played the maximum number of games." << endl;
            break;
          }
        }
      }

    } else {
      cout << "Invalid input, try again: ";
      cin >> choice;
    }

    // Conditions where the loop should stop
    if (cust1.get_drunkness() >= 100) {
      cout << "Bartender: CHOP CHOP let's go home bro!!" << endl;
      break;
    }

    if (cust1.money_left() <= 0) {
      cout << "Customer: Guess who's broke now LMAO" << endl;
      break;
    }

    if (cust1.get_hungriness() <= 0) {
      std::cout << "Customer: *Burp*" << std::endl;
      break;
    }

    // While choice is not 0, this loop will continue to go
    this->customer_report(cust1);
    this->menu_casino();
    cin >> choice;
    choice = this->validate_user_input(choice);
    choice = this->validate_numbers(0, 3, choice);
  }
}

void Casino::starting_module() {
  string name = this->user_name();
  int age = this->user_age();
  Customer c1(name, age);
  Employee e1("Bruno", 28);

  if (age >= 18) {
    this->starting_message(1, c1);
    this->module(c1, e1);

  } else if (age >= 0 || age < 18) {
    cout << "You need to be at least 18!!" << endl;
  }
}

void Casino::starting_message(int x, Customer c1) {
  if (x == 1) {
    cout << "Hi, " << c1.get_name() << ". Welcome to our mighty casino!!"
         << endl;
    cout << endl;
  } else if (x == 2) {
    cout << "You need to be at least 18!!" << std::endl;
  }
}

void Casino::print_FnB_Menu() {
  for (int i = 0; i < num_food; i++) {
    cout << i + 1 << food_menu[i]->get_name() << " | $"
         << food_menu[i]->get_price() << " | " << food_menu[i]->get_stock()
         << " left";
  }
  cout << "Let us know what you want by typing in the corresponding item "
          "number or 0 to exit: "
       << endl;
}

//void Casino:: print_betting_table() {
  //cout << "Welcome to our world of gambling" << endl; 
  //cout << "Please input how much money you want to bet: " << endl;
//}

int Casino::validate_user_input(int input) {
  while (cin.fail()) {  //! cin
    cout << "What you doing? Type in valid numbers only: ";
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

  while (age < 1 or age > 99) {
    cout << "That's not a reasonable answer: " << endl;
    cin >> age;
    age = this->validate_user_input(age);
  }
  return age;
}

bool Casino::validate_name(string name) {
  bool valid = false;

  for (int i = 0; i < name.length(); i++) {
    if ((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) ||
        name[i] == 32) {
      valid = true;
    } else {
      valid = false;
    }
  }
  return valid;
}

string Casino::user_name() {
  string name;
  cout << "What is your name? " << endl;
  cin >> name;

  while (validate_name(name) == 0) {
    cout << "Thats not a real name. Try again: " << endl;
    cin >> name;
  }
  return name;
}



int Casino::validate_numbers(int x, int y, int z) {
  while (z < x || z > y) {
    cout << "Please input a correct number: ";
    cin >> z;
    while (cin.fail()) {
      cout << "No letters please. Please input a correct number: ";
      cin.clear();
      cin.ignore(sizeof(unsigned int), '\n');
      cin >> z;
    }
  }
  return z;
}

void Casino::customer_report(Customer cust1) {
  cout << endl;
  cout << "Wallet    : $" << cust1.money_left() << endl;
  cout << "Drunkness : " << cust1.get_drunkness() << endl;
  cout << "Hungriness: " << cust1.get_hungriness() << endl;
}

Casino::~Casino() {  
for (int j = 0; j < num_food; j++) {
    delete food_menu[j];
  }

delete[] food_menu;
}