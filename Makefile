# Kompilator och flaggor
CXX = g++
CXXFLAGS = -Wall -g -Iinclude -std=c++17 -Wall -Wextra -pedantic -Woverloaded-virtual

# Mappar
SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include

# Källfiler och objekt
SRC = $(wildcard $(SRC_DIR)/*.cpp)
# APP_SRC = $(filter-out $(SRC_DIR)/*_test.cc, $(wildcard $(SRC_DIR)/*.cc))
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
TARGET = $(OBJ_DIR)/app

# Catch2 configuration
CATCH_HEADER = $(INCLUDE_DIR)/catch.hpp
CATCH_URL = https://github.com/catchorg/Catch2/releases/download/v2.13.7/catch.hpp

# Default
all: $(TARGET)

# Download Catch2 if not present
$(CATCH_HEADER):
	@echo "Downloading Catch2..."
	@curl -L $(CATCH_URL) -o $(CATCH_HEADER)

# Länkning
$(TARGET): $(OBJ) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Kompilering
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Skapa build-mapp
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Kör spelet
run: $(TARGET)
	@./$(TARGET)

# Rensa
clean:
	rm -rf $(OBJ_DIR)

# Download Catch2
catch: $(CATCH_HEADER)
	@echo "Catch2 downloaded successfully!"

.PHONY: all clean run catch