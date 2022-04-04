#include <vector>
#include <queue>


struct Edge {
    int from, to;
    long long cost;

    Edge(int to, long long cost) : from(-1), to(to), cost(cost) {}

    Edge(int from, int to, long long cost) : from(from), to(to), cost(cost) {}
};
using WeightedGraph = std::vector<std::vector<Edge>>;


std::vector<long long> dijkstra(const WeightedGraph &g, int start) {
    using P = std::pair<long long, int>;
    int n = g.size();
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
                pq.emplace(distance[e.to], e.to);
            }
        }
    }
    return distance;
}
