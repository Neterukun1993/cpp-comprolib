#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include <iostream>
#include <vector>
#include "../../src/graph/bfs-trace.hpp"


int main() {
    int n;
    std::cin >> n;

    Graph g(n);
    for (int i = 0; i < n; i++) {
        int v, k, nxt_v;
        std::cin >> v >> k;
        v -= 1;
        for (int j = 0; j < k; j++) {
            std::cin >> nxt_v;
            nxt_v -= 1;
            g[v].push_back(nxt_v);
        }
    }

    std::vector<int> parent;
    auto distance = bfs(g, 0, parent);

    for (int v = 0; v < n; v++) {
        auto path = trace_path(parent, v);
        if (path[0] != 0) std::cout << v + 1 << " " << -1 << std::endl;
        else std::cout << v + 1 << " " << (int)path.size() - 1<< std::endl;
    }
}
