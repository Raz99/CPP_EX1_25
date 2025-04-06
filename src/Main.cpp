// Email: razcohenp@gmail.com
#include <iostream> // For std::cout
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "MyLinkedList.hpp"
#include "MyQueue.hpp"
#include "MyPriorityQueue.hpp"
#include "MyUnionFind.hpp"

int main() {
    // Create a graph
    graph::Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    std::cout << "Graph created with 5 vertices and edges added:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (g.hasEdge(i, j)) {
                std::cout << "Edge from " << i << " to " << j << std::endl;
            }
        }
    }

    // Perform DFS starting from vertex 0
    std::cout << "\nPerforming DFS from vertex 0 -> Result:" << std::endl;
    graph::Graph dfsResult = graph::Algorithms::dfs(g, 0);
    dfsResult.print_graph();
    std::cout << std::endl;

    // Perform BFS starting from vertex 0
    std::cout << "Performing BFS from vertex 0 -> Result:" << std::endl;
    graph::Graph bfsResult = graph::Algorithms::bfs(g, 0);
    bfsResult.print_graph();
    std::cout << std::endl;

    return 0;
}