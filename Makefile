EXE_NAME = main

CC = g++
CC_FLAGS = -g -std=c++11 -O2 -Wall

build:
	$(CC) $(CC_FLAGS) main.cpp -o $(EXE_NAME)

run:
	./$(EXE_NAME)