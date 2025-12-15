CC=g++
EXECUTABLE=app
SFML_INCLUDE_PATH=/usr/local/include/SFML

# Directories
HEADERS=./include
SRC_DIR=src
OBJ_DIR=obj
TARGET=libtoolkit.so

CFLAGS=-fPIC -c -std=c++17 -Wall -pedantic-errors -I$(SFML_INCLUDE_PATH) -I$(HEADERS)
LDFLAGS=-shared

# Find Sources and Objects
SOURCES=$(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Default Target
all: $(TARGET)

# # Create static library (only useful for static library)
# $(TARGET): $(OBJECTS)
# 	ar rcs $@ $^

# Create shared library
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

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
	ldconfig

.PHONY: clean all install