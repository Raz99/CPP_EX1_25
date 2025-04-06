// Email: razcohenp@gmail.com
#include "../include/MyPriorityQueue.hpp"
#include <stdexcept> // For exceptions

namespace graph {
    // Constructor
    MyPriorityQueue::MyPriorityQueue(int cap) : capacity(cap), size(0) {
        if (cap <= 0) {
            throw std::invalid_argument("Capacity should be positive");
        }
        heap = new Node[cap];
    }

    // Copy constructor
    MyPriorityQueue::MyPriorityQueue(const MyPriorityQueue& other) : capacity(other.capacity), size(other.size) {
        heap = new Node[capacity];
        for (int i = 0; i < size; i++) {
            heap[i] = other.heap[i];
        }
    }

    // Destructor
    MyPriorityQueue::~MyPriorityQueue() {
        delete[] heap;
    }

    // Operator =
    MyPriorityQueue& MyPriorityQueue::operator=(const MyPriorityQueue& other) {
        if (this != &other) {
            delete[] heap;
            capacity = other.capacity;
            size = other.size;
            heap = new Node[capacity];
            for (int i = 0; i < size; i++) {
                heap[i] = other.heap[i];
            }
        }
        return *this;
    }

    // Add a vertex with a given priority to the queue
    void MyPriorityQueue::enqueue(int vertex, int priority) {
        if (size == capacity) {
            throw std::out_of_range("Priority queue is full");
        }
        heap[size] = {vertex, priority};
        heapifyUp(size);
        size++;
    }

    // Remove and return the vertex with the highest priority (lowest value)
    int MyPriorityQueue::dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        int vertex = heap[0].vertex;
        heap[0] = heap[--size];
        heapifyDown(0);
        return vertex;
    }

    // Check if the priority queue is empty
    bool MyPriorityQueue::isEmpty() const {
        return size == 0;
    }

    // Maintain the heap property after adding a new element
    void MyPriorityQueue::heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].priority <= heap[index].priority) {
                break;
            }
            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    // Maintain the heap property after removing an element
    void MyPriorityQueue::heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left].priority < heap[smallest].priority) {
                smallest = left;
            }
            if (right < size && heap[right].priority < heap[smallest].priority) {
                smallest = right;
            }
            if (smallest == index) {
                break;
            }
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

    // Swap two nodes in the heap
    void MyPriorityQueue::swap(Node &a, Node &b) {
        Node temp = a;
        a = b;
        b = temp;
    }
}