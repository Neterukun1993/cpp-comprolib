#include <tuple>
#include <vector>
#include <queue>


const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};


std::vector<std::vector<long long>> dijkstra(const std::vector<std::vector<long long>> &grid, int si, int sj) {
    using P = std::tuple<long long, int, int>;
    int h = grid.size();
    int w = grid[0].size();

    std::vector<std::vector<long long>> distance(h, std::vector<long long>(w, 1LL << 60));
    distance[si][sj] = 0LL;

    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.emplace(0LL, si, sj);

    while (not pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int& i = std::get<1>(p);
        int& j = std::get<2>(p);
        if (distance[i][j] < std::get<0>(p)) continue;

        for (int k = 0; k < 4; k++) {
            int nxt_i = i + di[k];
            int nxt_j = j + dj[k];
            if (nxt_i < 0 || h <= nxt_i) continue;
            if (nxt_j < 0 || w <= nxt_j) continue;
            if (distance[nxt_i][nxt_j] > distance[i][j] + grid[nxt_i][nxt_j]) {
                distance[nxt_i][nxt_j] = distance[i][j] + grid[nxt_i][nxt_j];
                pq.emplace(distance[nxt_i][nxt_j], nxt_i, nxt_j);
            }
        }
    }
    return distance;
}

