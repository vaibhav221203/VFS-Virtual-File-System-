# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

# Targets
TARGET = vfs_simulator
SRC = main.cpp src/File.cpp src/Directory.cpp src/FileSystem.cpp

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean target
clean:
	rm -f $(TARGET)
