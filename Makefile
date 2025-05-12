# Email: razcohenp@gmail.com
CXX = clang++
CXXFLAGS = -std=c++17 -Iinclude -Wall -O2
TARGET = prog
SRC = src/Graph.cpp src/Algorithms.cpp src/MyLinkedList.cpp src/MyQueue.cpp src/MyPriorityQueue.cpp src/MyUnionFind.cpp
TEST_SRC = tests/TestGraph.cpp tests/TestAlgorithms.cpp tests/TestLinkedList.cpp tests/TestQueue.cpp tests/TestPriorityQueue.cpp tests/TestUnionFind.cpp
TEST_EXEC = test_runner
DOCTEST_INCLUDE = -Itests

all: $(TARGET)

Main: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC) src/Main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(SRC) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(DOCTEST_INCLUDE) $^ -o $(TEST_EXEC)
	./$(TEST_EXEC)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_EXEC) *.o