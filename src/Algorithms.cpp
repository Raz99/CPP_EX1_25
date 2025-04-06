// Email: razcohenp@gmail.com
#include <stdexcept> // For exceptions
#include <climits> // For INT_MAX
#include "../include/Algorithms.hpp"
#include "../include/MyQueue.hpp"
#include "../include/MyPriorityQueue.hpp"
#include "../include/MyUnionFind.hpp"

namespace graph {
    enum Color { WHITE, GRAY, BLACK };

    // BFS
    Graph Algorithms::bfs(const Graph &g, int s) {
        int n = g.numOfVertices;
    
        // Check if the source vertex is valid
        if (s < 0 || s >= n) {
            throw std::invalid_argument("Source vertex is out of range");
        }
    
        // Create the BFS tree graph
        Graph bfsTree(n, s);
    
        Color* color = new Color[n]; // Color of vertices
        int* d = new int[n]; // Distance
        int* pi = new int[n]; // Predecessor

        // Initialize all vertices
        for (int u = 0; u < n; ++u) {
            color[u] = WHITE;
            d[u] = INT_MAX;
            pi[u] = -1; // Use -1 to indicate no predecessor
        }
    
        // Start BFS from the source vertex
        color[s] = GRAY;
        d[s] = 0; 
        pi[s] = -1; // No predecessor
    
        MyQueue queue(n); // Create a queue for BFS
        queue.enqueue(s); // Enqueue the source vertex
    
        while (!queue.isEmpty()) {
            int u = queue.dequeue();
            int* adjacentVertices = g.adjList[u].getAdjacentVertices();
            int count = adjacentVertices[0]; // Number of adjacent vertices
    
            // Iterate through all adjacent vertices
            for (int i = 1; i <= count; i++) {
                int v = adjacentVertices[i]; // Current adjacent vertex

                // If the vertex is unvisited
                if (color[v] == WHITE) {
                    color[v] = GRAY;
                    d[v] = d[u] + 1;
                    pi[v] = u;
                    bfsTree.addEdge(u, v, g.adjList[u].getWeight(v)); // Add edge to BFS tree with original weight
                    queue.enqueue(v);
                }
            }
    
            color[u] = BLACK; // Mark the vertex as fully explored
            delete[] adjacentVertices; // Finished with current vertex's adjacent vertices
        }
    
        delete[] color;
        delete[] d;
        delete[] pi;
    
        return bfsTree;
    }
    
    // DFS
    // Helper function
    void dfsVisit(const Graph &g, int u, Color color[], int d[], int f[], int pi[], int &time, Graph &dfsTree) {
        color[u] = GRAY;
        time++;
        d[u] = time; // Set discovery time
    
        int* adjacentVertices = g.getAdjList()[u].getAdjacentVertices();
        int count = adjacentVertices[0]; // Number of adjacent vertices
    
        // Iterate through all adjacent vertices
        for (int i = 1; i <= count; i++) {
            int v = adjacentVertices[i]; // Current adjacent vertex
            
            // If the vertex is unvisited
            if (color[v] == WHITE) {
                pi[v] = u; // Set predecessor
                dfsTree.addEdge(u, v, g.getAdjList()[u].getWeight(v)); // Add edge to DFS tree with original weight
                dfsVisit(g, v, color, d, f, pi, time, dfsTree);
            }
        }
    
        color[u] = BLACK; // Mark the vertex as fully explored
        time++;
        f[u] = time; // Set finish time
    
        delete[] adjacentVertices;
    }
    
    Graph Algorithms::dfs(const Graph &g, int s) {
        int n = g.numOfVertices;
    
        // Check if the source vertex is valid
        if (s < 0 || s >= n) {
            throw std::invalid_argument("Source vertex is out of range");
        }
    
        // Create the DFS tree graph
        Graph dfsTree(n, s);
    
        Color* color = new Color[n]; // Color of vertices
        int* d = new int[n]; // Discovery time
        int* f = new int[n]; // Finish time
        int* pi = new int[n]; // Predecessor
    
        // Initialize all vertices
        for (int i = 0; i < n; i++) {
            color[i] = WHITE;
            d[i] = -1; // Use -1 to indicate no discovery time
            f[i] = -1; // Use -1 to indicate no finish time
            pi[i] = -1; // Use -1 to indicate no predecessor
        }
    
        int time = 0; // Time counter
    
        // Start DFS from the source vertex
        if (color[s] == WHITE) {
            dfsVisit(g, s, color, d, f, pi, time, dfsTree);
        }
    
        // This ensures that all components of the graph are covered
        for (int u = 0; u < n; ++u) {
            // If the vertex is unvisited
            if (color[u] == WHITE) {
                dfsVisit(g, u, color, d, f, pi, time, dfsTree);
            }
        }
    
        delete[] color;
        delete[] d;
        delete[] f;
        delete[] pi;
    
        return dfsTree;
    }

    // Dijkstra
    Graph Algorithms::dijkstra(const Graph &g, int s) {
        int n = g.numOfVertices;
    
        // Check if the source vertex is valid
        if (s < 0 || s >= n) {
            throw std::invalid_argument("Source vertex is out of range");
        }
    
        // Check for negative weights
        for (int u = 0; u < n; ++u) {
            int* adjacentVertices = g.adjList[u].getAdjacentVertices();
            int count = adjacentVertices[0]; // Number of adjacent vertices
    
            // Iterate through all adjacent vertices
            for (int i = 1; i <= count; i++) {
                int weight = g.adjList[u].getWeight(adjacentVertices[i]); // Weight of edge (u, v)
                
                // If the weight is negative, throw an exception
                if (weight < 0) {
                    delete[] adjacentVertices;
                    throw std::invalid_argument("Graph contains negative weight edges");
                }
            }
    
            delete[] adjacentVertices;
        }
    
        // Create a graph to represent the shortest path tree
        Graph shortestPathTree(n, s);
    
        int* d = new int[n]; // Distances
        int* pi = new int[n]; // Predecessors (-1 for no predecessor)
        bool* inTree = new bool[n]; // Track if added to tree
    
        // Initialize all vertices
        for (int i = 0; i < n; i++) {
            d[i] = INT_MAX;
            pi[i] = -1; // No predecessor
            inTree[i] = false; // Not in the shortest path tree
        }
    
        d[s] = 0; // Distance of the source vertex
        MyPriorityQueue pq(n);
        pq.enqueue(s, 0); // Enqueue the source vertex with priority 0
    
        while (!pq.isEmpty()) {
            int u = pq.dequeue(); // Get the vertex with the minimum distance
    
            if (inTree[u]) continue; // Skip if already in the tree
            inTree[u] = true; // Mark as in the shortest path tree
    
            // If the vertex has a predecessor, add the edge to the tree
            if (pi[u] != -1) {
                int weight = g.adjList[pi[u]].getWeight(u);
                shortestPathTree.addEdge(pi[u], u, weight);
            }
    
            int* adjacentVertices = g.adjList[u].getAdjacentVertices();
            int count = adjacentVertices[0]; // Number of adjacent vertices
    
            // Iterate through all adjacent vertices (for each e leaving u)
            for (int i = 1; i <= count; i++) {
                int v = adjacentVertices[i];
                int weight = g.adjList[u].getWeight(v);

                // relax(e=(u, v))
                if (d[u] != INT_MAX && d[v] > d[u] + weight) {
                    d[v] = d[u] + weight;
                    pi[v] = u;
                    pq.enqueue(v, d[v]);  // DecreaseKey
                    shortestPathTree.addEdge(u, v, weight); // Add edge to the tree
                }
            }
    
            delete[] adjacentVertices;
        }
    
        delete[] d;
        delete[] pi;
        delete[] inTree;
    
        return shortestPathTree;
    }

    // Prim
    Graph Algorithms::prim(const Graph &g) {
        int n = g.numOfVertices;

        // Create a graph to represent the MST
        Graph mst(n);

        if (n == 0) {
            return mst; // Empty graph
        }

        int* keys = new int[n]; // Keys for vertices
        bool* included = new bool[n]; // Track included vertices
        int* parent = new int[n]; // Parents (-1 for no parent)

        // Initialization
        for (int i = 0; i < n; i++) {
            keys[i] = INT_MAX;
            included[i] = false;
            parent[i] = -1; // No parent
        }

        keys[0] = 0; // Start from vertex 0 and set its key to 0

        // Create a priority queue for the vertices
        MyPriorityQueue pq(n);
        pq.enqueue(0, 0);

        while (!pq.isEmpty()) {
            // Get the vertex with the minimum key
            int u = pq.dequeue(); // Get the vertex with the minimum key

            if (included[u]) continue; // Skip if already included
            included[u] = true; // Mark as included in the MST

            int* adjacentVertices = g.adjList[u].getAdjacentVertices();
            int count = adjacentVertices[0]; // Number of adjacent vertices

            // If the vertex has a parent, add the edge to the MST
            for (int i = 1; i <= count; i++) {
                int v = adjacentVertices[i];
                int weight = g.adjList[u].getWeight(v);

                // If v is not included and weight of (u,v) is smaller than current key of v
                if (!included[v] && weight < keys[v]) {
                    keys[v] = weight;
                    pq.enqueue(v, keys[v]);
                    parent[v] = u;
                }
            }

            delete[] adjacentVertices;
        }

        // Construct the MST
        for (int i = 1; i < n; i++) {
            if (parent[i] != -1) {
                mst.addEdge(parent[i], i, keys[i]);
            }
        }

        delete[] keys;
        delete[] included;
        delete[] parent;

        return mst;
    }

    // Kruskal
    // Helper struct to represent edges
    struct Edge {
        int src, dest, weight;
    };

    // Helper function to sort edges by weight (using bubble sort)
    void sortEdges(Edge* edges, int edgeCount) {
        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = 0; j < edgeCount - i - 1; j++) {
                if (edges[j].weight > edges[j + 1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    Graph Algorithms::kruskal(const Graph& g) {
        int n = g.numOfVertices;

        // Create a graph to represent the MST
        Graph mst(n);
        
        if (n == 0) { 
            return mst; // Empty graph
        }

        // Count total number of edges
        int edgeCount = 0;
        for (int u = 0; u < n; u++) {
            int* adjacentVertices = g.adjList[u].getAdjacentVertices();
            edgeCount += adjacentVertices[0];
            delete[] adjacentVertices;
        }

        Edge* edges = new Edge[edgeCount];
        int index = 0; // Index for edges

        // Collect all edges from the graph
        for (int u = 0; u < n; u++) {
            int* adjacentVertices = g.adjList[u].getAdjacentVertices();
            int count = adjacentVertices[0]; // Number of adjacent vertices

            // Iterate through all adjacent vertices
            for (int i = 1; i <= count; i++) {
                int v = adjacentVertices[i];
                int weight = g.adjList[u].getWeight(v);

                if (u < v) { // To avoid adding the same edge twice
                    edges[index++] = {u, v, weight};
                }
            }

            delete[] adjacentVertices;
        }

        // Sort edges by weight
        sortEdges(edges, index);

        MyUnionFind uf(n); // Union-Find structure to track connected components

        // Process each edge in sorted order
        for (int i = 0; i < index; i++) {
            int rootSrc = uf.find(edges[i].src);
            int rootDest = uf.find(edges[i].dest);

            // If including this edge does not form a cycle
            if (rootSrc != rootDest) {
                mst.addEdge(edges[i].src, edges[i].dest, edges[i].weight);
                uf.merge(rootSrc, rootDest); // Union the sets
            }
        }

        delete[] edges;

        return mst;
    }
}