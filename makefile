CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: test.out

test.out: main.o rsdl.o Game.o Taw.o Ball.o GameField.o Goal.o Player.o
	$(CC) main.o Game.o Taw.o Ball.o GameField.o rsdl.o $(CCFLAGS) -o test.out

main.o: main.cpp
	$(CC) -c main.cpp

rsdl.o: RSDL/src/rsdl.hpp RSDL/src/rsdl.cpp
	$(CC) -c RSDL/src/rsdl.cpp -o rsdl.o

Game.o: Game.cpp Taw.o Ball.o GameField.o Goal.o Player.o
	$(CC) -c Game.cpp

Taw.o: Taw.cpp
	$(CC) -c Taw.cpp

Ball.o: Ball.cpp
	$(CC) -c Ball.cpp

GameField.o: GameField.cpp
	$(CC) -c GameField.cpp

.PHONY: clean
clean:
	rm -r *.o