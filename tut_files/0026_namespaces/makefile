# Makefile for 0026_1_namespaces
Dog: 0026_1_Animal.o 0026_1_Dog.o 0026_1_namespaces.o
	g++ 0026_1_Dog.o 0026_1_Animal.o 0026_1_namespaces.o -o Dog

0026_1_Dog.o: 0026_1_Dog.cpp
	g++ -c 0026_1_Dog.cpp

0026_1_namespaces.o: 0026_1_namespaces.cpp
	g++ -c 0026_1_namespaces.cpp

clean:
	rm *.o *.exe