add_sub:main.o add.o sub.o
	g++ main.o add.o sub.o -o add_sub
main.o:
	g++ -c main.cpp -o main.o
add.o:add.cpp add.h
	g++ -c -o add.o add.cpp
sub.o:sub.cpp sub.h
	g++ -c -o sub.o sub.cpp
