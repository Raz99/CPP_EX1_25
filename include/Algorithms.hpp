// Email: razcohenp@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"

namespace graph {
    class Algorithms {
        public:
            // All methods are static because none of them need an instance of Algorithms class to be called
            static Graph bfs(const Graph &g, int s);
            static Graph dfs(const Graph &g, int s);
            static Graph dijkstra(const Graph &g, int s);
            static Graph prim(const Graph &g);
            static Graph kruskal(const Graph &g);

    };
}

#endif