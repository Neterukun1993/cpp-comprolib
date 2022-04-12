#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <iostream>
#include <vector>
#include "../../src/graph/dijkstra-trace.hpp"


int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;

    WeightedGraph graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long cost;
        std::cin >> u >> v >> cost;
        graph[u].emplace_back(v, cost);
    }

    std::vector<int> parent;
    auto distance = dijkstra(graph, s, parent);
    auto path = trace_path(parent, t);

    if (distance[t] == 1LL << 60) {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << distance[t] << " " << (int)path.size() - 1 << std::endl;
    for (int i = 0; i < (int)path.size() - 1; i++) {
        std::cout << path[i] << " " << path[i + 1] << std::endl;
    }
}
