#pragma once
#include "../graph-template.hpp"

template <typename T>
bool bellman_ford(const Graph<T> &g, const int start, std::vector<T> &distance) {
    assert(g.size() == (int)distance.size());

    constexpr T INF = std::numeric_limits<T>::max();
    std::fill(distance.begin(), distance.end(), INF);
    distance[start] = 0;

    for (int i = 0; i < g.size(); i++) {
        bool update = false;
        for (int v = 0; v < g.size(); v++) {
            for (const auto& e: g[v]) {
                if (distance[v] != INF && distance[e.to] > distance[v] + e.cost) {
                    distance[e.to] = distance[v] + e.cost;
                    update = true;
                }
            }
        }
        if (not update) {
            return true;
        }
    }
    return false;
}
