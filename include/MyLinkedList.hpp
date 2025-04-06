// Email: razcohenp@gmail.com
#ifndef MYLINKEDLIST_HPP
#define MYLINKEDLIST_HPP

namespace graph {
    class Node {
        public:
            // Data members
            int v;
            int w;
            Node* next;

            // Constructor
            Node(int vertex, int weight);
    };

    class MyLinkedList {
        private:
            // Data members
            Node* head;
        
        public:
            // Constructor
            MyLinkedList();
            
            // Copy constructor
            MyLinkedList(const MyLinkedList& other);

            // Destructor
            ~MyLinkedList();

            // Operator =
            MyLinkedList& operator=(const MyLinkedList& other);
            
            // Add a new node to the list (for an edge)
            void addNode(int dest, int weight);
            
            // Remove a node from the list (for removing an edge)
            bool removeNode(int dest);
            
            // Get the weight of an edge to a specific destination
            int getWeight(int dest);

            // Check if a destination exists in the list
            bool containsVertex(int vertex) const;
            
            // Print the list
            void print() const;

            // Return an array of the adjacent vertices
            int* getAdjacentVertices();

            // Allow access to private members
            friend class Graph;
            friend class Algorithms;
    };
}

#endif