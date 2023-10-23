# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall

# Directories
SRCDIR := src
BUILDDIR := build
TARGET := main

# Find source files in src directory and its subdirectories
SOURCES := $(wildcard $(SRCDIR)/**/*.cpp $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Targets
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -r $(BUILDDIR)
	rm $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

