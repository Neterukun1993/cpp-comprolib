#pragma once
#include "../graph-template.hpp"
#include "src/data-structure/union-find/union-find.hpp"

template <typename T>
T kruskal(int n, std::vector<Edge<T>> &edges) {
    // edgesは破壊的にソートされる
    std::sort(edges.begin(), edges.end(), [](const Edge<T> &a, const Edge<T> &b) { return a.cost < b.cost; });

    UnionFind uf(n);
    T total_cost = 0;
    for (const auto& e : edges) {
        if (not uf.same(e.from, e.to)) {
            uf.merge(e.from, e.to);
            total_cost += e.cost;
        }
    }
    return total_cost;
}

template <typename T>
std::vector<Edge<T>> kruskal_edges(int n, std::vector<Edge<T>> &edges) {
    // edgesは破壊的にソートされる
    std::sort(edges.begin(), edges.end(), [](const Edge<T> &a, const Edge<T> &b) { return a.cost < b.cost; });

    std::vector<Edge<T>> result;
    UnionFind uf(n);
    for (const auto& e : edges) {
        if (not uf.same(e.from, e.to)) {
            uf.merge(e.from, e.to);
            result.emplace_back(e);
        }
    }
    return result;
}
