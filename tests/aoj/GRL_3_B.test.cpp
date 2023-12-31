#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "../../src/template/template.hpp"
#include "../../src/graph/misc/low-link.hpp"

int main() {
    int v, e;
    std::cin >> v >> e;

    Graph<int> g(v, false);
    std::vector<Edge<int>> edges;
    for (int i = 0; i < e; i++) {
        int s, t;
        std::cin >> s >> t;
        if (s > t) std::swap(s, t);
        g.add_edge(s, t, 1, i);
        edges.emplace_back(s, t, 1, i);
    }

    LowLink lowlink(g);
    lowlink.build();

    auto result = lowlink.bridges;
    std::sort(result.begin(), result.end(), [&](const int &a, const int &b) {
        return std::make_pair(edges[a].from, edges[a].to) < std::make_pair(edges[b].from, edges[b].to);
    });
    for (auto v : result) std::cout << edges[v].from << " " << edges[v].to << std::endl;
}