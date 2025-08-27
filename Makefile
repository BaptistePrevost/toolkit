CC=g++
EXECUTABLE=app
SFML_INCLUDE_PATH=/home/bprevost/SFML-3.0.0/include

# Directories
HEADERS=./include
SRC_DIR=src
OBJ_DIR=obj
TARGET=libtoolkit.a

CFLAGS=-c -std=c++17 -Wall -pedantic-errors -I$(SFML_INCLUDE_PATH) -I$(HEADERS)

# Find Sources and Objects
SOURCES=$(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Default Target
all: $(TARGET)

# Create static library
$(TARGET): $(OBJECTS)
	ar rcs $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

install: $(TARGET)
	mkdir -p /usr/local/include/toolkit
	cp -r include/* /usr/local/include/toolkit
	cp $(TARGET) /usr/local/lib

.PHONY: all clean install