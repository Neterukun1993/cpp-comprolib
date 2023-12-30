#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../src/template/template.hpp"
#include "../../src/graph/shortest-path/dijkstra.hpp"

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
    dijkstra(g, s, distance);

    long long INF = std::numeric_limits<long long>::max();
    for (const auto& dist : distance) {
        if (dist == INF) std::cout << "INF" << std::endl;
        else std::cout << dist << std::endl;
    }
}
