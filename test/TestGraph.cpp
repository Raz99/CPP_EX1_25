// Email: razcohenp@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Graph.hpp"
#include <stdexcept>

using namespace graph;

TEST_CASE("Testing creation of Graph") {
    SUBCASE("Creating a graph") {
        Graph g(3);
        CHECK_NOTHROW(g.addEdge(0, 2));
        CHECK_NOTHROW(g.addEdge(0, 1));
        CHECK_NOTHROW(g.addEdge(1, 2));
    }

    SUBCASE("Creating graph with negative number of vertices") {
        CHECK_NOTHROW(Graph g(0)); // Empty graph should be valid 
        CHECK_THROWS_AS(Graph g(-5), std::invalid_argument);
    }
}

TEST_CASE("Testing addition of edges") {
    Graph g(5);

    SUBCASE("Adding valid edges") {
        CHECK_NOTHROW(g.addEdge(0, 1)); // With efault weight
        CHECK_NOTHROW(g.addEdge(0, 4, 10)); // With custom weight
        CHECK_NOTHROW(g.addEdge(2, 3, 5));  // With custom weight
    }

    SUBCASE("Adding edges with invalid vertices") {
        CHECK_THROWS(g.addEdge(-1, 2));
        CHECK_THROWS_AS(g.addEdge(-1, 2), std::out_of_range);
        CHECK_THROWS_AS(g.addEdge(1, -2), std::out_of_range);
        CHECK_THROWS_AS(g.addEdge(5, 2), std::out_of_range);
        CHECK_THROWS_AS(g.addEdge(1, 6), std::out_of_range);
    }
}

TEST_CASE("Removing edges") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    SUBCASE("Removing valid and invalid edges") {
        g.removeEdge(0, 1);
        CHECK_THROWS_AS(g.removeEdge(0, 1), std::runtime_error); // Edge should be already removed
        g.removeEdge(2, 3);
        CHECK_THROWS_AS(g.removeEdge(2, 3), std::runtime_error); // Edge should be already removed
    }
}