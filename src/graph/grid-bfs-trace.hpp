#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>


const std::string direction = "RLDU";
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};


std::vector<std::vector<int>> grid_bfs(const std::vector<std::string> &grid, int si, int sj,
                                       std::vector<std::vector<std::pair<int, int>>> &parent, char wall = '#') {
    const int h = grid.size();
    const int w = grid[0].size();

    parent.resize(h, std::vector<std::pair<int, int>>(w, {-1, -1}));
    std::vector<std::vector<int>> distance(h, std::vector<int>(w, -1));
    std::queue<std::pair<int, int>> que;

    distance[si][sj] = 0;
    que.emplace(si, sj);
    while (not que.empty()) {
        auto p = que.front();
        que.pop();
        for (int k = 0; k < 4; k++) {
            int nxt_i = p.first + di[k];
            int nxt_j = p.second + dj[k];
            if (nxt_i < 0 || h <= nxt_i) continue;
            if (nxt_j < 0 || w <= nxt_j) continue;
            if (grid[nxt_i][nxt_j] == wall) continue;
            if (distance[nxt_i][nxt_j] != -1) continue;
            distance[nxt_i][nxt_j] = distance[p.first][p.second] + 1;
            parent[nxt_i][nxt_j] = {p.first, p.second};
            que.emplace(nxt_i, nxt_j);
        }
    }
    return distance;
}


std::vector<std::pair<int, int>> trace_path(const std::vector<std::vector<std::pair<int, int>>> &parent, int gi, int gj) {
    std::vector<std::pair<int, int>> path;
    std::pair<int, int> v = {gi, gj};
    while (v.first != -1 && v.second != -1) {
        path.push_back(v);
        v = parent[v.first][v.second];
    }
    std::reverse(path.begin(), path.end());
    return path;
}


std::string trace_route(const std::vector<std::vector<std::pair<int, int>>> &parent, int gi, int gj) {
    auto path = trace_path(parent, gi, gj);
    std::string route;
    for (int i = 0; i < (int)path.size() - 1; i++) {
        for (int k = 0; k < 4; k++) {
            int nxt_i = path[i].first + di[k];
            int nxt_j = path[i].second + dj[k];
            if (nxt_i == path[i + 1].first && nxt_j == path[i + 1].second) route.push_back(direction[k]);
        }
    }
    return route;
}