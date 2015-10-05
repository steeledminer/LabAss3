#
#This is the make file for assignment3.cpp
#
craps : assignment3.o
	g++ assignment3.o -o assignment3

craps.o :
	g++ -c assignment3.cpp

clean :
	rm assignment3.o assignment3
