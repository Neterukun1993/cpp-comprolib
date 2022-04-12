#include <vector>
#include <queue>
#include <algorithm>


struct Edge {
    int from, to;
    long long cost;

    Edge(int to, long long cost) : from(-1), to(to), cost(cost) {}

    Edge(int from, int to, long long cost) : from(from), to(to), cost(cost) {}
};
using WeightedGraph = std::vector<std::vector<Edge>>;


std::vector<long long> dijkstra(const WeightedGraph &g, int start, std::vector<int> &parent) {
    using P = std::pair<long long, int>;
    const int n = g.size();

    parent.resize(n, -1);
    std::vector<long long> distance(n, 1LL << 60);
    distance[start] = 0LL;

    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.emplace(0LL, start);

    while (not pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int v = p.second;
        if (distance[v] < p.first) continue;

        for (const auto& e : g[v]) {
            if (distance[e.to] > distance[v] + e.cost) {
                distance[e.to] = distance[v] + e.cost;
                parent[e.to] = v;
                pq.emplace(distance[e.to], e.to);
            }
        }
    }
    return distance;
}


std::vector<int> trace_path(const std::vector<int> &parent, int goal) {
    std::vector<int> path;
    for (int v = goal; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}
