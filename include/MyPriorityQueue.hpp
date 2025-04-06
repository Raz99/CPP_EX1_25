// Email: razcohenp@gmail.com
#ifndef MYPRIORITYQUEUE_HPP
#define MYPRIORITYQUEUE_HPP

namespace graph {
    class MyPriorityQueue {
        private:
            // Node struct for the priority queue
            struct Node {
                int vertex;
                int priority;
            };

            // Data members
            Node* heap;
            int capacity;
            int size;

            // Maintain the heap property after adding a new element
            void heapifyUp(int index);

            // Maintain the heap property after removing an element
            void heapifyDown(int index);

            // Swap two nodes in the heap
            void swap(Node &a, Node &b);

        public:
            // Constructor
            MyPriorityQueue(int capacity);
            
            // Copy constructor
            MyPriorityQueue(const MyPriorityQueue& other);

            // Destructor
            ~MyPriorityQueue();

            // Operator =
            MyPriorityQueue& operator=(const MyPriorityQueue& other);

            // Add a vertex with a given priority to the queue
            void enqueue(int vertex, int priority);

            // Remove and return the vertex with the highest priority (lowest value)
            int dequeue();

            // Check if the priority queue is empty
            bool isEmpty() const;
    };
}

#endif