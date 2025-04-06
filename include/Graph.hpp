// Email: razcohenp@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "MyLinkedList.hpp"

namespace graph {
    class Graph {
        private:
            // Data members
            int numOfVertices;
            MyLinkedList* adjList;
            int rootVertex; // For DFS' requirement

        public:
            // Constructor
            Graph(int n);

            // Constructor with root vertex parameter
            Graph(int n, int root);

            // Copy constructor
            Graph(const Graph& other);

            // Destructor
            ~Graph();

            // Operator =
            Graph& operator=(const Graph& other);

            // Methods
            // Add an edge to the graph
            void addEdge(int src, int dest, int weight = 1);

            // Remove an edge from the graph
            void removeEdge(int src, int dest);

            // Print the graph
            void print_graph() const;
            
            // Additional methods
            bool hasEdge(int src, int dest) const; 

            // Methods for the root vertex
            // Set the root vertex
            void setRoot(int root);

            // Get the root vertex
            int getRoot() const;

            // Getter methods (these are very simple, then I decided to implement them in .hpp)
            // Get the adjacency list
            MyLinkedList* getAdjList() const {
                return adjList;
            }

            // Get the number of vertices
            int getNumOfVertices() const {
                return numOfVertices;
            }

            // Allow access to private members
            friend class Algorithms;
    };
}

#endif