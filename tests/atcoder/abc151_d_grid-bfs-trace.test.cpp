#define PROBLEM "https://atcoder.jp/contests/abc151/tasks/abc151_d"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include "../../src/graph/grid-bfs-trace.hpp"


bool is_correct_route(std::string &route, std::vector<std::string> &grid, int si, int sj, int gi, int gj) {
    bool res = true;
    if (grid[si][sj] == '#') res = false;
    for (const auto& dire : route) {
        if (dire == 'R') sj += 1;
        if (dire == 'L') sj -= 1;
        if (dire == 'D') si += 1;
        if (dire == 'U') si -= 1;
        if (grid[si][sj] == '#') res = false;
    }
    if (si != gi || sj != gj) res = false;
    return res;
}


int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> grid(h);
    for (auto& s : grid) { std::cin >> s; }

    int ans = 0;
    for (int si = 0; si < h; si++) {
        for (int sj = 0; sj < w; sj++) {
            if (grid[si][sj] == '#') continue;
            std::vector<std::vector<std::pair<int, int>>> parent;
            auto dist = grid_bfs(grid, si, sj, parent, '#');
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (dist[i][j] != -1) {
                        auto route = trace_route(parent, i, j);
                        assert(is_correct_route(route, grid, si, sj, i, j));
                        ans = std::max(ans, (int)route.size());
                    }
                }
            }
        }
    }
    std::cout << ans << std::endl;
}
