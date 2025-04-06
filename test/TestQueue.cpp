// Email: razcohenp@gmail.com
#include "doctest.h"
#include "../include/MyQueue.hpp"
#include <stdexcept> // For exceptions

TEST_CASE("Testing MyQueue implementation") {
    graph::MyQueue q;

    SUBCASE("Queue is initially empty") {
        CHECK(q.isEmpty() == true);
    }

    SUBCASE("Enqueuing elements") {
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        CHECK(q.isEmpty() == false);
        // Assuming peek or front method is implemented to check front element
        CHECK(q.dequeue() == 10);
        CHECK(q.dequeue() == 20);
        CHECK(q.dequeue() == 30);
    }

    SUBCASE("Dequeuing elements") {
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        CHECK(q.dequeue() == 10);
        CHECK(q.dequeue() == 20);
        CHECK(q.dequeue() == 30);
        CHECK(q.isEmpty() == true);
    }

    SUBCASE("Queue underflow") {
        CHECK_THROWS_AS(q.dequeue(), std::out_of_range);
    }
}