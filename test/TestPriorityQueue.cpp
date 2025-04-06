// Email: razcohenp@gmail.com
#include "doctest.h"
#include "../include/MyPriorityQueue.hpp"
#include <stdexcept> // For exceptions

TEST_CASE("Testing MyPriorityQueue implementation") {
    graph::MyPriorityQueue pq(10);

    SUBCASE("Priority Queue is initially empty") {
        CHECK(pq.isEmpty() == true);
    }

    SUBCASE("Enqueuing elements with priorities") {
        pq.enqueue(10, 2);
        pq.enqueue(20, 1);
        pq.enqueue(30, 3);

        CHECK(pq.isEmpty() == false);
        CHECK(pq.dequeue() == 20); // Highest priority (lowest value)
    }

    SUBCASE("Dequeuing elements") {
        pq.enqueue(10, 2);
        pq.enqueue(20, 1);
        pq.enqueue(30, 3);

        CHECK(pq.dequeue() == 20); // Highest priority
        CHECK(pq.dequeue() == 10); // Next highest priority
        CHECK(pq.dequeue() == 30); // Lowest priority
        CHECK(pq.isEmpty() == true);
    }

    SUBCASE("Priority Queue underflow") {
        CHECK_THROWS_AS(pq.dequeue(), std::out_of_range);
    }
}