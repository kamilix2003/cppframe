BUILD_DIR := ./tmp/build
SRC_DIR := ./src

SRC_FILES := ${SRC_DIR}/*.cpp

temp:
	g++ -c ${SRC_FILES}
	g++ main.o Player.o Display.o -o ${BUILD_DIR}/Run
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