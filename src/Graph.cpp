// Email: razcohenp@gmail.com
#include "../include/Graph.hpp"
#include <stdexcept> // For exceptions
#include <iostream> // For print

namespace graph {
    // Constructor
    Graph::Graph(int n) : numOfVertices(n), rootVertex(-1) {
        if (n < 0) {
            throw std::invalid_argument("Number of vertices cannot be negative");
        }
        adjList = new MyLinkedList[n];
    }

    // Copy constructor
    Graph::Graph(const Graph& other) : numOfVertices(other.numOfVertices), rootVertex(other.rootVertex) {
        adjList = new MyLinkedList[numOfVertices];
        for (int i = 0; i < numOfVertices; ++i) {
            adjList[i] = other.adjList[i];
        }
    }

    // Destructor
    Graph::~Graph() {
        delete[] adjList;
    }

    // Operator =
    Graph& Graph::operator=(const Graph& other) {
        if (this != &other) {
            delete[] adjList;
            numOfVertices = other.numOfVertices;
            rootVertex = other.rootVertex;
            adjList = new MyLinkedList[numOfVertices];
            for (int i = 0; i < numOfVertices; ++i) {
                adjList[i] = other.adjList[i];
            }
        }
        return *this;
    }

    // Constructor with root vertex
    Graph::Graph(int n, int root) : numOfVertices(n) {
        if (root < 0 || root >= n) {
            throw std::out_of_range("Root vertex is out of range");
        }
        
        rootVertex = root;
        adjList = new MyLinkedList[n];
    }

    // Add an edge to the graph
    void Graph::addEdge(int src, int dest, int weight) {
        // Check if vertices are valid
        if(src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }

        // Add edge (src -> dest)
        adjList[src].addNode(dest, weight);

        // Since this is an undirected graph, also add edge (dest -> src)
        adjList[dest].addNode(src, weight);
    }

    // Remove an edge from the graph
    void Graph::removeEdge(int src, int dest) {
        // Check if vertices are valid
        if(src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }

        // Check if the edge exists
        if (!adjList[src].containsVertex(dest) || !adjList[dest].containsVertex(src)) {
            throw std::runtime_error("Edge does not exist");
        }

        // Remove edge (src -> dest)
        adjList[src].removeNode(dest);

        // Since this is an undirected graph, also remove edge (dest -> src)
        adjList[src].removeNode(src);
    }

    // Get the number of vertices
    void Graph::print_graph() const {
        for(int i = 0; i < numOfVertices; i++) {
            std::cout << "[" << i << "] -> ";
            adjList[i].print();
        }
    }

    // Check if an edge exists
    bool Graph::hasEdge(int src, int dest) const {
        if(src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices) {
            throw std::out_of_range("Vertex index out of range");
        }

        return adjList[src].containsVertex(dest);
    }

    // Set the root vertex
    void Graph::setRoot(int root) {
        if (root < 0 || root >= numOfVertices) {
            throw std::out_of_range("Root vertex is out of range");
        }
        
        rootVertex = root;
    }
    
    // Get the root vertex
    int Graph::getRoot() const {
        return rootVertex;
    }
}