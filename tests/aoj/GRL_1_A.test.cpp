#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include <vector>
#include "../../src/graph/dijkstra.hpp"


int main() {
    int n, m, s;
    std::cin >> n >> m >> s;

    WeightedGraph g(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        std::cin >> u >> v >> d;
        g[u].emplace_back(v, d);
    }
    std::vector<long long> distance = dijkstra(g, s);

    for (const auto& dist : distance) {
        if (dist == 1LL << 60) std::cout << "INF" << std::endl;
        else std::cout << dist << std::endl;
    }
}
