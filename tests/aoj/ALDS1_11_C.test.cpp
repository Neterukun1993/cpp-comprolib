#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include "../../src/template/template.hpp"
#include "../../src/graph/shortest-path/bfs.hpp"

int main() {
    int n;
    std::cin >> n;

    Graph<int> g(n);
    for (int i = 0; i < n; i++) {
        int v, k, nxt_v;
        std::cin >> v >> k;
        v -= 1;
        for (int j = 0; j < k; j++) {
            std::cin >> nxt_v;
            nxt_v -= 1;
            g.add_edge(v, nxt_v, 1, -1);
        }
    }

    std::vector<int> distance(n);
    bfs(g, 0, distance);
    for (int v = 0; v < n; v++) {
        std::cout << v + 1 << " " << distance[v] << std::endl;
    }
}
