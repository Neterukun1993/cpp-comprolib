#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include <iostream>
#include <vector>
#include "../../src/graph/bfs.hpp"


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

    std::vector<int> distance = bfs(g, 0);
    for (int v = 0; v < n; v++) {
        std::cout << v + 1 << " " << distance[v] << std::endl;
    }
}
