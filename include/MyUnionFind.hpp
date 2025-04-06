// Email: razcohenp@gmail.com
#ifndef MYUNIONFIND_HPP
#define MYUNIONFIND_HPP

namespace graph {
    class MyUnionFind {
        private:
            // Data members
            int size;
            int* parent;
            int* rank;

        public:
            // Constructors
            MyUnionFind(int n);

            // Copy constructor
            MyUnionFind(const MyUnionFind& other);

            // Destructor
            ~MyUnionFind();

            // Operator =
            MyUnionFind& operator=(const MyUnionFind& other);

            // Find the root of the set containing x
            int find(int x);

            // Merge the sets containing x and y
            void merge(int x, int y);
    };
}

#endif