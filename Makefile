BUILD_DIR := ./tmp/build
SRC_DIR := ./src

temp:
	g++ -c ./src/main.cpp ./src/Player.cpp ./src/Display.cpp
	g++ main.o Player.o Display.o -o Run
	rm *.o

clean: Run
	@echo "cleaning up"
	rm main.o Player.o Display.o

link: ./main.o ./Player.o ./Display.o
	@echo "linking"
	g++ main.o Player.o Display.o -o Run

compile:
	@echo "compiling"
	g++ -c ./src/main.cpp ./src/Player.cpp ./src/Display.cpp