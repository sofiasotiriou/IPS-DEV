# C++ Tests
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++11
CXXTG = cxxtestgen
CXXTGFLAGS = --error-printer
EXE = testFunctions
SRC_DIR = ../src
BIN_DIR = ../bin
SRC = $(SRC_DIR)/checkOrthonormality.cpp $(SRC_DIR)/compute.cpp
RUNNERS = testFunctions.cpp
CXX_PATH = -I/usr/include/cxxtest

all: $(EXE)

%.cpp: %.hpp 
	$(CXXTG) $(CXXTGFLAGS) -o $@ $<

$(EXE): $(RUNNERS) $(SRC)
	$(CXX) -o $(BIN_DIR)/$@ $(CXXFLAGS) $^ $(CXX_PATH)


test_dir:
	mkdir -p tests

test: $(EXE)
	./$(BIN_DIR)/$(EXE)

.PHONY: all clean test

clean: 
	@echo "Cleaning test"
	rm -f $(RUNNERS)
	rm -f $(BIN_DIR)/$(EXE)


