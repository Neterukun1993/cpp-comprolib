#include <vector>
#include <algorithm>
#include "../../src/data-structure/union-find.hpp"


struct Edge {
    int from, to;
    long long cost;

    Edge(int to, long long cost) : from(-1), to(to), cost(cost) {}

    Edge(int from, int to, long long cost) : from(from), to(to), cost(cost) {}
};


long long kruskal(int n, std::vector<Edge> edges) {
    std::sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.cost < b.cost;
    });
    UnionFind uf(n);
    long long total_cost = 0LL;
    for (const auto& e : edges) {
        if (not uf.same(e.from, e.to)) {
            uf.merge(e.from, e.to);
            total_cost += e.cost;
        }
    }
    return total_cost;
}
