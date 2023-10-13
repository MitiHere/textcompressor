# Makefile for Hello World C++ program

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

# Source files
SRCS = filereader.cpp 

# Object files directory
OBJ_DIR = ../build/obj/

# Object files
OBJS = $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))

# Target executable
TARGET = ../build/filereader

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: 
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
