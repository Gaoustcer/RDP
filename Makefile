objects = ./build/fileread.o
srcpath = ./src/*.cpp 
includepath = ../include
mainincludepath = ./include 
main:$(objects) main.cpp
	g++ main.cpp $(objects) -o main -I ./include
# ./build/fileread.o:./src/fileread.cpp

$(objects):./build/%.o:./src/%.cpp
	g++ -c $< -o $@ -I ./include