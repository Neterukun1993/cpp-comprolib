#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include <vector>
#include "../../src/graph/bellman-ford.hpp"


int main() {
    int n, m, s;
    std::cin >> n >> m >> s;

    WeightedGraph g(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        std::cin >> u >> v >> d;
        g[u].emplace_back(v, d);
    }
    auto result = bellman_ford(g, s);
    if (not result.first) std::cout << "NEGATIVE CYCLE" << std::endl;
    else {
        for (const auto& val : result.second) {
            if (val == 1LL << 60) std::cout << "INF" << std::endl;
            else std::cout << val << std::endl;
        }
    }
}
