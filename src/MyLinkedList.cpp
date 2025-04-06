// Email: razcohenp@gmail.com
#include "../include/MyLinkedList.hpp"
#include <iostream> // For print

namespace graph {
    // Node's constructor
    Node::Node(int dest, int weight) : v(dest), w(weight), next(nullptr) {}

    // Constructor
    MyLinkedList::MyLinkedList() : head(nullptr) {}

    // Copy constructor
    MyLinkedList::MyLinkedList(const MyLinkedList& other) : head(nullptr) {
        if (other.head) {
            head = new Node(other.head->v, other.head->w); // Copy the head node
            Node* current = head;
            Node* otherCurrent = other.head->next;

            // Copy the rest of the nodes
            while (otherCurrent) {
                current->next = new Node(otherCurrent->v, otherCurrent->w);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }

    // Operator =
    MyLinkedList& MyLinkedList::operator=(const MyLinkedList& other) {
        // Ensure that we're not assigning to the same object
        if (this != &other) {
            Node* current = head;
            
            // Delete the current list
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            
            // Copy the list
            head = nullptr;
            if (other.head) {
                head = new Node(other.head->v, other.head->w);
                current = head;
                Node* otherCurrent = other.head->next;
                
                while (otherCurrent) {
                    current->next = new Node(otherCurrent->v, otherCurrent->w);
                    current = current->next;
                    otherCurrent = otherCurrent->next;
                }
            }
        }
        return *this;
    }

    // Deconstructor
    MyLinkedList::~MyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Add a new node to the list (for an edge)
    void MyLinkedList::addNode(int dest, int weight) {
        Node* newNode = new Node(dest, weight);

        if(newNode == nullptr) {
            return;
        }

        // If the list is empty, make the new node as the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // If the destination already exists, update the weight
        if (containsVertex(dest)) {
            Node* current = head;

            // Search for the destination node
            while (current != nullptr && current->v != dest) {
                current = current->next;
            }

            if (current != nullptr) {
                current->w = weight; // Update the weight
                delete newNode; // Delete the new node since we don't need it
            }
            return;
        }

        // Otherwise, add the new node in the beginning of the list
        newNode->next = head;
        head = newNode;
    }

    // Remove a node from the list (for removing an edge)
    bool MyLinkedList::removeNode(int dest) {
        if (head == nullptr) {
            return false;
        }

        // If the head is the node to remove
        if (head->v == dest) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        // Otherwise, search for the node
        Node* current = head;
        while (current->next != nullptr && current->next->v != dest) {
            current = current->next;
        }

        // If found, remove it
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }

        return false; // Node not found
    }

    // Check if a destination exists in the list
    bool MyLinkedList::containsVertex(int vertex) const {
        Node* current = head;
        
        while (current != nullptr) {
            if (current->v == vertex) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    // Get the weight of an edge to a specific destination
    int MyLinkedList::getWeight(int dest) {
        Node* current = head;

        while(current != nullptr) {
            if(current->v == dest) {
                return current->w;
            }
            current = current->next;
        }

        return -1; // Edge doesn't exist
    }

    // Print the list
    void MyLinkedList::print() const {
        Node* current = head;

        while(current != nullptr) {
            std::cout << "{" << current->v << ", " << current->w << "} ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    // Return an array of the adjacent vertices
    int* MyLinkedList::getAdjacentVertices() {
        // Count how many adjacent vertices are in the linked list
        int count = 0;
        Node* current = head;
        
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        
        int* adjacent = new int[count + 1]; // +1 for the count at index 0
        adjacent[0] = count; // Store the count at index 0
        
        // If there are no vertices, just return the array with count 0
        if (count == 0) {
            return adjacent;
        }
        
        // Fill the array with adjacent vertices
        current = head;
        int index = 1;  // Start at index 1 since index 0 has the count
        
        while (current != nullptr) {
            adjacent[index++] = current->v; // Store the vertex
            current = current->next;
        }
        
        return adjacent;
    }
}