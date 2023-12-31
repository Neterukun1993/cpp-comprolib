#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include "../../src/template/template.hpp"
#include "../../src/graph/misc/low-link.hpp"

int main() {
    int v, e;
    std::cin >> v >> e;

    Graph<int> g(v, false);
    for (int i = 0; i < e; i++) {
        int s, t;
        std::cin >> s >> t;
        g.add_edge(s, t, 1, i);
    }

    LowLink lowlink(g);
    lowlink.build();

    auto result = lowlink.articulation_points;
    std::sort(result.begin(), result.end());
    for (auto v : result) std::cout << v << std::endl;
}