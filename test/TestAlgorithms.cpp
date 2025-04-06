// Email: razcohenp@gmail.com
#include "doctest.h"
#include <stdexcept> // For exceptions
#include "../include/Algorithms.hpp"
#include "../include/Graph.hpp"

// BFS
TEST_CASE("Testing BFS algorithm") {
    // Create a graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    // Perform BFS starting from vertex 0
    graph::Graph bfsTree = graph::Algorithms::bfs(g, 0);

    // Verify the BFS tree structure
    CHECK(bfsTree.hasEdge(0, 1));
    CHECK(bfsTree.hasEdge(0, 2));
    CHECK(bfsTree.hasEdge(1, 3));
    CHECK(bfsTree.hasEdge(2, 4));
}

TEST_CASE("Testing BFS with invalid source vertex") {
    // Create a graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    // Perform BFS with invalid source vertex
    CHECK_THROWS_AS(graph::Algorithms::bfs(g, -1), std::invalid_argument);
    CHECK_THROWS_AS(graph::Algorithms::bfs(g, 5), std::invalid_argument);
}

TEST_CASE("Testing BFS with empty graph") {
    // Create an empty graph
    graph::Graph g(0);

    // Perform BFS on the empty graph
    CHECK_THROWS_AS(graph::Algorithms::bfs(g, 0), std::invalid_argument);
}

TEST_CASE("Testing BFS root vertex") {
    // Create a graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    // Perform BFS starting from vertex 0
    graph::Graph bfsTree = graph::Algorithms::bfs(g, 1);

    // Verify the root vertex of the BFS tree
    CHECK(bfsTree.getRoot() == 1);
}

// DFS
TEST_CASE("Testing DFS algorithm") {
    // Create a graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    // Perform DFS starting from vertex 0
    graph::Graph dfsTree = graph::Algorithms::dfs(g, 0);

    // Verify the DFS tree structure
    CHECK(dfsTree.hasEdge(0, 1));
    CHECK(dfsTree.hasEdge(1, 3));
    CHECK(dfsTree.hasEdge(0, 2));
    CHECK(dfsTree.hasEdge(2, 4));
}

TEST_CASE("Testing DFS with invalid source vertex") {
    // Create a graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    // Perform DFS with invalid source vertex
    CHECK_THROWS_AS(graph::Algorithms::dfs(g, -1), std::invalid_argument);
    CHECK_THROWS_AS(graph::Algorithms::dfs(g, 5), std::invalid_argument);
}

TEST_CASE("Testing DFS with empty graph") {
    // Create an empty graph
    graph::Graph g(0);

    // Perform DFS on the empty graph
    CHECK_THROWS_AS(graph::Algorithms::dfs(g, 0), std::invalid_argument);
}

TEST_CASE("Testing DFS with different root vertices") {
    // Create a graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    // Perform DFS starting from vertex 1
    graph::Graph dfsTree1 = graph::Algorithms::dfs(g, 1);

    // Verify the DFS tree structure starting from vertex 1
    CHECK(dfsTree1.hasEdge(1, 0));
    CHECK(dfsTree1.hasEdge(0, 2));
    CHECK(dfsTree1.hasEdge(2, 4));
    CHECK(dfsTree1.hasEdge(1, 3));

    // Perform DFS starting from vertex 2
    graph::Graph dfsTree2 = graph::Algorithms::dfs(g, 2);

    // Verify the DFS tree structure starting from vertex 2
    CHECK(dfsTree2.hasEdge(2, 0));
    CHECK(dfsTree2.hasEdge(0, 1));
    CHECK(dfsTree2.hasEdge(1, 3));
    CHECK(dfsTree2.hasEdge(2, 4));
}

TEST_CASE("Testing DFS with forest case") {
    // Create a graph with 6 vertices (0-5)
    graph::Graph g(6);

    // Add edges to create two disconnected components
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);


    // Perform DFS starting from vertex 0
    graph::Graph dfsForest = graph::Algorithms::dfs(g, 0);

    // Should include both components
    CHECK(dfsForest.hasEdge(0, 1));
    CHECK(dfsForest.hasEdge(1, 2));
    CHECK(dfsForest.hasEdge(3, 4));
    CHECK(dfsForest.hasEdge(4, 5));
}

// Dijkstra
TEST_CASE("Testing Dijkstra algorithm") {
    // Create a weighted graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 7);
    g.addEdge(4, 3, 9);

    // Perform Dijkstra starting from vertex 0
    graph::Graph shortestPathTree = graph::Algorithms::dijkstra(g, 0);

    // Verify the shortest path tree structure
    CHECK(shortestPathTree.hasEdge(0, 1));
    CHECK(shortestPathTree.hasEdge(0, 2));
    CHECK(shortestPathTree.hasEdge(2, 1));
    CHECK(shortestPathTree.hasEdge(1, 3));
    CHECK(shortestPathTree.hasEdge(2, 4));
    CHECK_FALSE(shortestPathTree.hasEdge(3, 4)); // Should not have edge from vertex 3 to 4 in the shortest path tree
}

TEST_CASE("Testing Dijkstra with invalid source vertex") {
    // Create a weighted graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 7);
    g.addEdge(4, 3, 9);

    // Perform Dijkstra with invalid source vertex
    CHECK_THROWS_AS(graph::Algorithms::dijkstra(g, -1), std::invalid_argument);
    CHECK_THROWS_AS(graph::Algorithms::dijkstra(g, 5), std::invalid_argument);
}

TEST_CASE("Testing Dijkstra with empty graph") {
    // Create an empty graph
    graph::Graph g(0);

    // Perform Dijkstra on the empty graph
    CHECK_THROWS_AS(graph::Algorithms::dijkstra(g, 0), std::invalid_argument);
}

TEST_CASE("Testing Dijkstra with negative weights") {
    // Create a weighted graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph with some negative weights
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 1, -4); // Negative weight
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 7);
    g.addEdge(4, 3, 9);

    // Perform Dijkstra starting from vertex 0
    CHECK_THROWS_AS(graph::Algorithms::dijkstra(g, 0), std::invalid_argument);
}

TEST_CASE("Testing Dijkstra with disconnected graph") {
    // Create a weighted graph with 6 vertices (0-5)
    graph::Graph g(6);

    // Add edges to create two disconnected components
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(3, 4, 5);
    g.addEdge(4, 5, 6);

    // Perform Dijkstra starting from vertex 0
    graph::Graph shortestPathTree1 = graph::Algorithms::dijkstra(g, 0);

    // Verify the shortest path tree structure for the first component
    CHECK(shortestPathTree1.hasEdge(0, 1));
    CHECK(shortestPathTree1.hasEdge(1, 2));
    CHECK_FALSE(shortestPathTree1.hasEdge(3, 4)); // Should not have edges from the second component

    // Perform Dijkstra starting from vertex 3
    graph::Graph shortestPathTree2 = graph::Algorithms::dijkstra(g, 3);

    // Verify the shortest path tree structure for the second component
    CHECK(shortestPathTree2.hasEdge(3, 4));
    CHECK(shortestPathTree2.hasEdge(4, 5));
    CHECK_FALSE(shortestPathTree2.hasEdge(0, 1)); // Should not have edges from the first component
}

// Prim
TEST_CASE("Testing Prim algorithm") {
    // Create a weighted graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    // Perform Prim's algorithm
    graph::Graph mst = graph::Algorithms::prim(g);

    // Verify the minimum spanning tree structure
    CHECK(mst.hasEdge(0, 1));
    CHECK(mst.hasEdge(1, 2));
    CHECK(mst.hasEdge(1, 4));
    CHECK(mst.hasEdge(0, 3));
    CHECK_FALSE(mst.hasEdge(2, 4)); // Should not have edge from vertex 2 to 4 in the MST
}

TEST_CASE("Testing Prim with empty graph") {
    // Create an empty graph
    graph::Graph g(0);

    // Perform Prim on the empty graph
    CHECK(graph::Algorithms::prim(g).getNumOfVertices() == 0);
}

// Kruskal
TEST_CASE("Testing Kruskal algorithm") {
    // Create a weighted graph with 5 vertices
    graph::Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    // Perform Kruskal's algorithm
    graph::Graph mst = graph::Algorithms::kruskal(g);

    // Verify the minimum spanning tree structure
    CHECK(mst.hasEdge(0, 1));
    CHECK(mst.hasEdge(1, 2));
    CHECK(mst.hasEdge(1, 4));
    CHECK(mst.hasEdge(0, 3));
    CHECK_FALSE(mst.hasEdge(2, 4)); // Should not have edge from vertex 2 to 4 in the MST
}

TEST_CASE("Testing Kruskal with empty graph") {
    // Create an empty graph
    graph::Graph g(0);

    // Perform Kruskal on the empty graph
    CHECK(graph::Algorithms::kruskal(g).getNumOfVertices() == 0);
}