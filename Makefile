output: Main.o Person.o Customer.o Employee.o FnB_menu.o Drink.o Food.o Games.o Hard_Game.o Easy_Game.o Casino.o 
	g++ Main.o Person.o Customer.o Employee.o FnB_menu.o Drink.o Food.o Games.o Hard_Game.o Easy_Game.o Casino.o  -o output

Main.o: Main.cpp
	g++ -c Main.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp 

Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp

Employee.o: Employee.cpp Employee.h
	g++ -c Employee.cpp

FnB_menu.o: FnB_menu.cpp FnB_menu.h
	g++ -c FnB_menu.cpp

Drink.o: Drink.cpp Drink.h
	g++ -c Drink.cpp

Games.o: Games.cpp Games.h  
	g++ -c Games.cpp

Hard_Game.o: Hard_Game.cpp Hard_Game.h
	g++ -c Hard_Game.cpp	

Easy_Game.o: Easy_Game.cpp Easy_Game.h
	g++ -c Easy_Game.cpp	

Food.o: Food.cpp Food.h
	g++ -c Food.cpp	

Casino.o: Casino.cpp Casino.h
	g++ -c Casino.cpp

clean:
	rm *.o output		