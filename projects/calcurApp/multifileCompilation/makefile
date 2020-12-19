# My First Makefile!
guess_game: Main.o withFiles.o
	g++ Main.o withFiles.o -o guess_game

Main.o: Main.cpp
	g++ -c Main.cpp

withFiles.o: withFiles.cpp
	g++ -c withFiles.cpp

clean:
	rm .*o guess_game