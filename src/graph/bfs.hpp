#include <vector>
#include <queue>
using Graph = std::vector<std::vector<int>>;


std::vector<int> bfs(const Graph &g, int start) {
    int n = g.size();
    std::vector<int> distance(n, -1);
    std::queue<int> que;

    distance[start] = 0;
    que.push(start);
    while (not que.empty()) {
        int v = que.front();
        que.pop();

        for (int nxt_v : g[v]) {
            if (distance[nxt_v] != -1) continue;
            distance[nxt_v] = distance[v] + 1;
            que.push(nxt_v);
        }
    }
    return distance;
}
