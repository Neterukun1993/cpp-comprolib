#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include "../../src/template/template.hpp"
#include "../../src/graph/shortest-path/bellman-ford.hpp"

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;

    Graph<long long> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long d;
        std::cin >> u >> v >> d;
        g.add_edge(u, v, d, i);
    }
    std::vector<long long> distance(n);
    auto result = bellman_ford(g, s, distance);
    if (!result) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
    } else {
        auto INF = std::numeric_limits<long long>::max();
        for (const auto& val : distance) {
            if (val == INF) std::cout << "INF" << std::endl;
            else std::cout << val << std::endl;
        }
    }
}
