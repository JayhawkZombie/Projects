Lab02: main.o Box.o Stack.o
	g++ -g -std=c++11 main.o Box.o Stack.o -o Lab02
main.o: main.cpp Box.h Stack.h
	g++ -g -std=c++11 -c main.cpp
Box.o: Box.h Box.cpp
	g++ -g -std=c++11 -c Box.cpp
Stack.o: Stack.h Stack.cpp Box.h
	g++ -g -std=c++11 -c Stack.cpp
