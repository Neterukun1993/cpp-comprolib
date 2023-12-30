#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../src/template/template.hpp"
#include "../../src/graph/minimum-spanning-tree/kruskal.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Edge<long long>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long cost;
        std::cin >> u >> v >> cost;
        edges.emplace_back(u, v, cost, i);
    }
    auto ans = kruskal(n, edges);

    auto ans_edges = kruskal_edges(n, edges);
    long long ans2 = 0;
    for (auto e : ans_edges) { ans2 += e.cost; }

    assert(ans == ans2);

    std::cout << ans << std::endl;
}
