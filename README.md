# C++ Exercise #1

## Overview

This project is a C++ implementation of common graph algorithms. It provides a custom graph data structure along with several algorithms for traversing and analyzing graphs, including Breadth-First Search (BFS), Depth-First Search (DFS), Dijkstra's Shortest Path and Minimum Spanning Tree algorithms (Prim's and Kruskal's).

## Features

### Data Structures

- **Graph**: A custom implementation of a graph data structure using adjacency lists
- **MyLinkedList**: A linked list implementation for representing adjacency lists
- **MyQueue**: A queue implementation for BFS algorithm
- **MyPriorityQueue**: A priority queue for Dijkstra's and Prim's algorithms
- **MyUnionFind**: A Union-Find data structure for Kruskal's algorithm

### Algorithms

- **BFS (Breadth-First Search)**: Traverses graph in breadth-first manner from a source vertex
- **DFS (Depth-First Search)**: Traverses graph in depth-first manner from a source vertex
- **Dijkstra's Algorithm**: Finds the shortest path from a source vertex to all other vertices
- **Prim's Algorithm**: Finds a minimum spanning tree for a weighted undirected graph
- **Kruskal's Algorithm**: Finds a minimum spanning tree for a weighted undirected graph

## Project Structure

The project is organized into the following directories:

- **include/**: Header files for all classes
- **src/**: Implementation files for all classes
- **test/**: Test files (not yet implemented)

## Getting Started

### Prerequisites

- Make (for building using the Makefile)

### Building and Running

- `make Main` - Compiles and runs the demonstration file.
- `make test` - Compiles and runs the unit tests.
- `make valgrind` - Checks for memory leaks using valgrind.
- `make clean` - Removes all irrelevant files after execution.

## Sources

Please take a look at the [attached PDF](https://github.com/Raz99/CPP_EX1_25/blob/386a8a14aad7617eb42c41e6c19adf27bc013bdf/sources.pdf).

## Author

Raz Cohen - [GitHub](https://github.com/Raz99), [LinkedIn](https://www.linkedin.com/in/raz-cohen-p)
