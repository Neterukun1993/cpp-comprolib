#pragma once
#include "../graph-template.hpp"

template <typename T>
void dijkstra(const Graph<T> &g, const int start, std::vector<T> &distance) {
    assert(g.size() == (int)distance.size());

    constexpr T INF = std::numeric_limits<T>::max();
    std::fill(distance.begin(), distance.end(), INF);
    distance[start] = 0;

    using P = std::pair<T, int>;
    static std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.emplace(distance[start], start);

    while (not pq.empty()) {
        const auto p = pq.top();
        pq.pop();

        const int v = p.second;
        if (distance[v] < p.first) continue;
        for (const auto& e : g[v]) {
            if (distance[e.to] > distance[v] + e.cost) {
                distance[e.to] = distance[v] + e.cost;
                pq.emplace(distance[e.to], e.to);
            }
        }
    }
}
