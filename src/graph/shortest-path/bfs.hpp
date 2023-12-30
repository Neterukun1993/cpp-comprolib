#pragma once
#include "../graph-template.hpp"

template <typename T>
void bfs(const Graph<T> &g, const int start, std::vector<int> &distance) {
    assert(g.size() == (int)distance.size());

    std::fill(distance.begin(), distance.end(), -1);
    distance[start] = 0;

    static std::queue<int> que;
    que.push(start);

    while (not que.empty()) {
        const int v = que.front();
        que.pop();

        for (const auto& e: g[v]) {
            if (distance[e.to] != -1) continue;
            distance[e.to] = distance[v] + 1;
            que.push(e.to);
        }
    }
}
