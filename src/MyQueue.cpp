// Email: razcohenp@gmail.com
#include "../include/MyQueue.hpp"
#include <stdexcept> // For exceptions

namespace graph {
    // Constructor
    MyQueue::MyQueue(int cap) : front(0), rear(0), size(0), capacity(cap) {
        if(cap <= 0) {
            throw std::invalid_argument("Capacity should be positive");
        }

        capacity = cap;
        front = 0;
        rear = 0;
        size = 0;
        data = new int[cap];
        
        // Initialize all elements to (-1)
        for (int i = 0; i < cap; i++) {
            data[i] = -1;
        }
    }

    // Copy constructor
    MyQueue::MyQueue(const MyQueue& other) : front(other.front), rear(other.rear), size(other.size), capacity(other.capacity) {
        data = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    MyQueue::~MyQueue() {
        delete[] data;
    }

    // Operator =
    MyQueue& MyQueue::operator=(const MyQueue& other) {
        if (this != &other) {
            delete[] data;
            front = other.front;
            rear = other.rear;
            size = other.size;
            capacity = other.capacity;
            data = new int[capacity];
            for (int i = 0; i < capacity; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Add a new value to the queue
    bool MyQueue::enqueue(int newValue) {
        bool ans = true;

        // Check if the queue is full
        if(size == capacity) {
            ans = false;
        }

        // If the queue is not full, add the new value
        else {
            data[rear] = newValue;
            rear = (rear + 1) % capacity; // if rear == n-1 -> rear = 0
            size++;
        }
        
        return ans;
    }

    // Remove a value from the queue
    int MyQueue::dequeue() {
        int ans;

        if(isEmpty()) {
            // Queue is empty
            throw std::out_of_range("Queue is empty");
        }

        else {
            ans = data[front];
            front = (front + 1) % capacity; // if front == n-1 -> front = 0
            size--;
        }

        return ans;
    }

    // Return whether the queue is empty or not
    bool MyQueue::isEmpty() {
        return size == 0;
    }
}