#include <vector>
#include <string>
#include <queue>


const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};


std::vector<std::vector<int>> grid_bfs(const std::vector<std::string> &grid, int si, int sj, char wall = '#') {
    const int h = grid.size();
    const int w = grid[0].size();
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
            que.emplace(nxt_i, nxt_j);
        }
    }
    return distance;
}
