program: main.o BST.o Website.o myUtil.o
	g++ -g -Wall -std=c++17 main.o BST.o Website.o myUtil.o -o program

main.o: main.cpp
	g++ -g -c -std=c++17 -Wall main.cpp -o main.o

BST.o: BST.cpp
	g++ -g -c -std=c++17 -Wall BST.cpp -o BST.o

Website.o: Website.cpp
	g++ -g -c -std=c++17 -Wall Website.cpp -o Website.o

myUtil.o: myUtil.cpp
	g++ -g -c -std=c++17 -Wall myUtil.cpp -o myUtil.o

.PHONY: all clean check

all: program

clean:
	rm -f *.o
	rm -f ./program

check:
	valgrind --leak-check=full ./program
