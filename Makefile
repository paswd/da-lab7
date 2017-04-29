COMPILLER=g++
FLAGS=-Wextra -Wall -Werror -pedantic -std=c++11

all: start

start: main.o
	$(COMPILLER) $(FLAGS) -o da-lab7 main.o

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp
