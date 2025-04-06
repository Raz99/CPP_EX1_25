// Email: razcohenp@gmail.com
#include "doctest.h"
#include "../include/MyUnionFind.hpp"

TEST_CASE("Testing MyUnionFind implementation") {
    graph::MyUnionFind uf(5);

    SUBCASE("Initial state") {
        for (int i = 0; i < 5; ++i) {
            CHECK(uf.find(i) == i);
        }
    }

    SUBCASE("Union operations") {
        uf.merge(0, 1);
        uf.merge(1, 2);
        uf.merge(3, 4);

        CHECK(uf.find(0) == uf.find(1));
        CHECK(uf.find(1) == uf.find(2));
        CHECK(uf.find(3) == uf.find(4));
        CHECK(uf.find(0) != uf.find(3));
    }

    SUBCASE("Path compression") {
        uf.merge(0, 1);
        uf.merge(1, 2);

        CHECK(uf.find(0) == uf.find(2));
        CHECK(uf.find(1) == uf.find(2));
    }

    SUBCASE("Union by rank") {
        uf.merge(0, 1);
        uf.merge(2, 3);
        uf.merge(3, 4);
        uf.merge(1, 4);

        CHECK(uf.find(0) == uf.find(4));
        CHECK(uf.find(1) == uf.find(4));
        CHECK(uf.find(2) == uf.find(4));
        CHECK(uf.find(3) == uf.find(4));
    }
}