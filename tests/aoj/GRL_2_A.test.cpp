#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>
#include <vector>
#include "../../src/graph/kruskal.hpp"


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long cost;
        std::cin >> u >> v >> cost;
        edges.emplace_back(u, v, cost);
    }
    auto ans = kruskal(n, edges);
    std::cout << ans << std::endl;
}
