# objects = ./include/*.h
# filelist = :$(wildcard ./include/*.h)
# all:
# 	echo $(objects)
# 	echo $(filelist)

includepath = ./include/*.h
srcpath = ./src/*.cpp
objectpath = ./build/head.o ./build/test.o
main:$(objectpath)
	g++ main.cpp $(objectpath) -o main -I ./include
$(objectpath):./build/%.o:./src/%.cpp
	g++ -c $< -o $@ -I ../include
