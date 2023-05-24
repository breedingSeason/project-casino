#ifndef FNB_MENU_H
#define FNB_MENU_H
#include <string>
using namespace std;

class FnB_menu{
    protected:
    string name;
    int stock;//quantity that are in store
    int price;
    string type_food;
    public:
    FnB_menu();//default constructor
    FnB_menu(string name,int stock, int price, string type);//constructor
    string get_name();//get
    int get_price();//get
    int get_stock();//get
    int get_type(); // returns an integer based on the type of food ordered
    int prepare_food();//update stock every time a food item is ordered, decrease the stock by input x
    bool change_stock(); //ensures the ordered food is in stock and the stock is not negative, return true if stock>=0
    virtual int get_nutrition_info();//will return different values based on derived class

};
#endif