// Email: razcohenp@gmail.com
#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP

namespace graph {
    class MyQueue {
        private:
            // Data members
            int front;
            int rear;
            int size;
            int capacity;
            int* data;
        
        public:
            // Constructor
            MyQueue(int cap = 10);

            // Copy constructor
            MyQueue(const MyQueue& other);

            // Destructor
            ~MyQueue();

            // Operator =
            MyQueue& operator=(const MyQueue& other);

            // Add a new value to the queue
            bool enqueue(int newValue);

            // Remove a value from the queue
            int dequeue();

            // Return whether the queue is empty or not
            bool isEmpty();
    };
}

#endif