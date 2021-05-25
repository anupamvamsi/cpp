# Makefile for 17_test
game.exe: main.o Creature.o Player.o
	g++ main.o Creature.o Player.o -o game.exe

Creature.o: Creature.cpp
	g++ -c Creature.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o *.exe