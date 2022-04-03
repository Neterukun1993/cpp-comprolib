#include <iostream>
#include <vector>


struct Edge {
    int to;
    long long cost;
    Edge(int to_, long long cost_) : to(to_), cost(cost_) {}
};
using WeightedGraph = std::vector<std::vector<Edge>>;


std::pair<bool, std::vector<long long>> bellman_ford(const WeightedGraph &g, int start) {
    int n = g.size();
    long long INF = 1LL << 60;
    std::vector<long long> distance(n, INF);
    distance[start] = 0LL;

    for (int i = 0; i < n; i++) {
        bool update = false;
        for (int v = 0; v < n; v++) {
            for (auto& e: g[v]) {
                if (distance[v] != INF && distance[e.to] > distance[v] + e.cost) {
                    distance[e.to] = distance[v] + e.cost;
                    update = true;
                }
            }
        }
        if (not update) {
            return {true, distance};
        }
    }
    return {false, distance};
}
