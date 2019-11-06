# Makefile for IF-Game

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g # compiler flags

# ****************************************************

# Specify what I need in the end. One single executable

# # divisionExecutable depends on main.o div.o
main : main.o engine.o utils.o
	$(CXX) $(CXXFLAGS) -o main main.o engine.o utils.o 

#-----------------------------------------------------------------
# Main relies on the engine header file
main.o : main.cpp engine.h
	$(CXX) $(CXXFLAGS) -c main.cpp
# Engine relies on engine objects and utils
engine.o : engine.cpp engine-objs.h utils.h
	$(CXX) $(CXXFLAGS) -c engine.cpp
# Compile utils
utils.o : utils.cpp
	$(CXX) $(CXXFLAGS) -c utils.cpp