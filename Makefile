CXX = g++
CXXFLAGS_COMMON = -fPIC -Wall -Wextra -Iinclude -I/usr/local/include/SFML

SRC = $(wildcard src/**/*.cpp src/*.cpp)
OBJ_DEBUG = $(SRC:src/%.cpp=build/debug/%.o)
OBJ_RELEASE = $(SRC:src/%.cpp=build/release/%.o)

LIB_DEBUG = lib/debug/libtoolkit_d.so
LIB_RELEASE = lib/release/libtoolkit.so

### DEBUG ###
CXXFLAGS_DEBUG = $(CXXFLAGS_COMMON) -g -O0
LDFLAGS_DEBUG = -shared -lsfml-graphics -lsfml-window -lsfml-system

### RELEASE ###
CXXFLAGS_RELEASE = $(CXXFLAGS_COMMON) -O3 -DNDEBUG
LDFLAGS_RELEASE = -shared -s -lsfml-graphics -lsfml-window -lsfml-system

### RULES ###
all: debug release

debug: $(LIB_DEBUG)
release: $(LIB_RELEASE)

$(LIB_DEBUG): $(OBJ_DEBUG)
	@mkdir -p $(@D)
	$(CXX) $(LDFLAGS_DEBUG) -o $@ $^

$(LIB_RELEASE): $(OBJ_RELEASE)
	@mkdir -p $(@D)
	$(CXX) $(LDFLAGS_RELEASE) -o $@ $^

build/debug/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

build/release/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS_RELEASE) -c $< -o $@

clean:
	rm -rf build lib