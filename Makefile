all: main.o menu.o database.o product.o
	g++ main.o menu.o database.o product.o -o run

main.o: main.cpp
	g++ -c main.cpp
	
menu.o: menu.cpp
	g++ -c menu.cpp

database.o: database.cpp
	g++ -c database.cpp

product.o: product.cpp
	g++ -c product.cpp

clean:
	rm -rf *~ *.o