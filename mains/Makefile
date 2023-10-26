# Makefile for Hello World C++ program

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall 

# Source files
SRCS = main.cpp ../funzipper/funzipper.cpp  ../funzipper/vectoredTxt.cpp ../funzipper/uwordmap.cpp

# Object files directory
OBJ_DIR = ../build/obj/

# Object files
OBJS = $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))


# Target executable
TARGET = ../build/main

all: $(TARGET) run 

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	
run: 
	./$(TARGET);ls -la
