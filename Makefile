objects = ./build/fileread.o 
srcpath = ./src/*.cpp 
includepath = ../include
mainincludepath = ./include 
main:$(objects):
	g++ main.cpp $(objectpath) -o main -I $(mainincludepath)
$(objects):./build/%.o:./src/%.cpp
	g++ -c $< -o $@ -I $(includepath)