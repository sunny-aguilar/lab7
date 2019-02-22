# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	February 17, 2019
# Description:	Makefile for Lab 7

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += queue.o

HPPs = queue.hpp

CPPs = main.cpp
CPPs += queue.cpp


# Targets needed to bring the executable up to date
Node: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Node $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

queue.o: queue.hpp


# Clean-up operations
clean:
	rm Node *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Node

zip:
	zip -D Lab7_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf
