#include<iostream>
#include <string>
#include "FnB_menu.cpp"
using namespace std;

class UnitTestFnb{
    protected:
    void testFnB(){
        FnB_menu coke("Coke",2,5);
        if(coke.get_name()!="Coke"){
            cout<<"Name error!"<<endl;
        }
        if(coke.get_price()!=5){
            cout<<"Price error!"<<endl;
        }
        if(coke.get_stock()!=2){
            cout<<"Stock error!"<<endl;
        }
        if(coke.prepare_food(1)!=1){
            cout<<"Prepare food false!"<<endl;
        }
        coke.prepare_food(2);
        if(coke.change_stock()==true){
            cout<<"Change stock false!"<<endl;
        }
    }
    public:
    void runFnBtest(){
        testFnB();
    }
};