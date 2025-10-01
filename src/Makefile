# src Compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++11 
HDR_DIR = ../headers
OBJ_DIR = ../obj
BIN_DIR = ../bin
OBJS = compute.o export.o checkOrthonormality.o checkEn.o main.o
EXE = main

all: $(OBJ_DIR) $(BIN_DIR) $(EXE)

# Create directories if they do not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compilate object files and executable

$(EXE): $(addprefix $(OBJ_DIR)/, $(OBJS)) 
	$(CXX)  $^ -o $(BIN_DIR)/$@ $(LIBS)

$(OBJ_DIR)/%.o: %.cpp $(HDR_DIR)/%.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.cpp $(HDR_DIR)/compute.hpp $(HDR_DIR)/export.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@
	

.PHONY: all clean
# Clean the objs and the exe
clean:
	@echo "Cleaning objs and exe"
	rm -rf $(OBJ_DIR)/* 
	rm -rf $(BIN_DIR)/*
