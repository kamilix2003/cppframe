CC = gcc

compile:
	#{CC} ./src/main.cpp ./src/Display.cpp ./src/Player.cpp -c
	#{CC} ./main.o ./Display.o ./Player.o -o run.exe
	./run.exe