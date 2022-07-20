#makefile for the program- add lines for each card
CC = g++
CFLAGS = -std=c++11

test: main.o board.o card.o axe.o dog.o candle.o ninja.o panther.o wizard.o spider.o wasp.o soldier.o sword.o snake.o
	$(CC) main.o board.o card.o axe.o dog.o candle.o ninja.o panther.o wizard.o spider.o wasp.o soldier.o sword.o snake.o -o test

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

board.o: board.h board.cpp
	$(CC) -c board.cpp $(CFLAGS)

card.o: card.h card.cpp
	$(CC) -c card.cpp $(CFLAGS)

axe.o: axe.h axe.cpp
	$(CC) -c axe.cpp $(CFLAGS)

dog.o: dog.h dog.cpp
	$(CC) -c dog.cpp $(CFLAGS)

candle.o: candle.h candle.cpp
	$(CC) -c candle.cpp $(CFLAGS)

ninja.o: ninja.h ninja.cpp
	$(CC) -c ninja.cpp $(CFLAGS)

panther.o: panther.h panther.cpp
	$(CC) -c panther.cpp $(CFLAGS)

wizard.o: wizard.h wizard.cpp
	$(CC) -c wizard.cpp $(CFLAGS)

spider.o: spider.h spider.cpp
	$(CC) -c spider.cpp $(CFLAGS)

wasp.o: wasp.h wasp.cpp
	$(CC) -c wasp.cpp $(CFLAGS)

soldier.o: soldier.h soldier.cpp
	$(CC) -c soldier.cpp $(CFLAGS)

sword.o: sword.h sword.cpp
	$(CC) -c sword.cpp $(CFLAGS)

snake.o: snake.h snake.cpp
	$(CC) -c snake.cpp $(CFLAGS)

clean:
	rm *.o test
