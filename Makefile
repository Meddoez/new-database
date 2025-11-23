# Kompilator och flaggor
CXX = g++
CXXFLAGS = -Wall -g -Iinclude -std=c++17 -Wall -Wextra -pedantic -Woverloaded-virtual

# Mappar
SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include

# Catch2 configuration
CATCH_HEADER = $(INCLUDE_DIR)/catch.hpp
CATCH_URL = https://github.com/catchorg/Catch2/releases/download/v2.13.7/catch.hpp

# Shared object files (needed by both test and main)
SHARED_OBJ = $(OBJ_DIR)/database.o $(OBJ_DIR)/user.o

# Test program
TEST_SRC = $(SRC_DIR)/table_test.cpp
TEST_TARGET = $(OBJ_DIR)/test

# Main program
MAIN_SRC = $(SRC_DIR)/main.cc
MAIN_TARGET = $(OBJ_DIR)/main

# Default target - build both
all: test main

# Download Catch2 if not present
$(CATCH_HEADER):
	@echo "Downloading Catch2..."
	@curl -L $(CATCH_URL) -o $(CATCH_HEADER)

# Build test program
test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRC) $(SHARED_OBJ) | $(OBJ_DIR) $(CATCH_HEADER)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_SRC) $(SHARED_OBJ)

# Build main program
main: $(MAIN_TARGET)

$(MAIN_TARGET): $(MAIN_SRC) $(SHARED_OBJ) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_SRC) $(SHARED_OBJ)

# Compile shared object files
$(OBJ_DIR)/database.o: $(SRC_DIR)/database.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/user.o: $(SRC_DIR)/user.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Skapa build-mapp
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Run test program
run-test: test
	@./$(TEST_TARGET)

# Run main program
run-main: main
	@./$(MAIN_TARGET)

# Rensa
clean:
	rm -rf $(OBJ_DIR)

# Download Catch2
catch: $(CATCH_HEADER)
	@echo "Catch2 downloaded successfully!"

.PHONY: all clean test main run-test run-main catch