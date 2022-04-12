#include <vector>
#include <queue>
using Graph = std::vector<std::vector<int>>;


std::vector<int> bfs(const Graph &g, int start, std::vector<int> &parent) {
    const int n = g.size();

    parent.resize(n, -1);
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
            parent[nxt_v] = v;
            que.push(nxt_v);
        }
    }
    return distance;
}


std::vector<int> trace_path(const std::vector<int> &parent, int goal) {
    std::vector<int> path(0);
    for (int v = goal; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}
