# Makefile for Hello World C++ program

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Source files
SRCS = hellomain.cpp helloworlder.cpp

# Object files directory
OBJ_DIR = ../build/obj/

# Object files
OBJS = $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))

# Target executable
TARGET = ../build/helloWorld

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
