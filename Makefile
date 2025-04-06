# Email: razcohenp@gmail.com
CXX = clang++
CXXFLAGS = -std=c++17 -Iinclude -Wall -O2
TARGET = prog
SRC = src/Graph.cpp src/Algorithms.cpp src/MyLinkedList.cpp src/MyQueue.cpp src/MyPriorityQueue.cpp src/MyUnionFind.cpp
TEST_SRC = test/TestGraph.cpp test/TestAlgorithms.cpp test/TestLinkedList.cpp test/TestQueue.cpp test/TestPriorityQueue.cpp test/TestUnionFind.cpp
TEST_EXEC = test_runner
DOCTEST_INCLUDE = -Itest

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