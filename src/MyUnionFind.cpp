// Email: razcohenp@gmail.com
#include "../include/MyUnionFind.hpp"

namespace graph {
    // Constructor
    MyUnionFind::MyUnionFind(int n) : size(n) {
        parent = new int[n];
        rank = new int[n];

        // Initialize the parent and rank arrays
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Copy constructor
    MyUnionFind::MyUnionFind(const MyUnionFind& other) : size(other.size) {
        parent = new int[size];
        rank = new int[size];

        // Copy the data from the other object
        for (int i = 0; i < size; ++i) {
            parent[i] = other.parent[i];
            rank[i] = other.rank[i];
        }
    }

    // Destructor
    MyUnionFind::~MyUnionFind() {
        delete[] parent;
        delete[] rank;
    }

    // Operator =
    MyUnionFind& MyUnionFind::operator=(const MyUnionFind& other) {
        if (this != &other) {
            delete[] parent;
            delete[] rank;
            size = other.size;
            parent = new int[size];
            rank = new int[size];

            // Copy the data from the other object
            for (int i = 0; i < size; ++i) {
                parent[i] = other.parent[i];
                rank[i] = other.rank[i];
            }
        }

        return *this;
    }

    // Find the root of the set containing x
    int MyUnionFind::find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Merge the sets containing x and y
    void MyUnionFind::merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
}