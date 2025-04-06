// Email: razcohenp@gmail.com
#include "doctest.h"
#include "../include/MyLinkedList.hpp"

using namespace graph;

TEST_CASE("Testing MyLinkedList implementation") {
    MyLinkedList list; // Use the default constructor
    
    SUBCASE("Adding nodes") {
        list.addNode(2, 5);
        CHECK(list.containsVertex(2));
        CHECK(list.getWeight(2) == 5);
        
        list.addNode(3, 10);
        CHECK(list.containsVertex(3));
        CHECK(list.getWeight(3) == 10);
    }
    
    SUBCASE("Updating weight") {
        list.addNode(2, 5);
        list.addNode(2, 8); // Update weight
        CHECK(list.getWeight(2) == 8);
    }
    
    SUBCASE("Removing nodes") {
        list.addNode(2, 5);
        list.addNode(3, 10);
        
        CHECK(list.removeNode(2));
        CHECK_FALSE(list.containsVertex(2));
        CHECK(list.containsVertex(3));
        
        CHECK(list.removeNode(3));
        CHECK_FALSE(list.containsVertex(3));
        
        CHECK_FALSE(list.removeNode(4)); // Try to remove a node that does not exist
    }
}