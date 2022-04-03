#define PROBLEM "https://atcoder.jp/contests/abc151/tasks/abc151_d"

#include <iostream>
#include <vector>
#include <string>
#include "../../src/graph/grid-bfs.hpp"



int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> grid(h);
    for (auto& s : grid) { std::cin >> s; }

    int ans = 0;
    for (int si = 0; si < h; si++) {
        for (int sj = 0; sj < w; sj++) {
            if (grid[si][sj] == '#') continue;
            auto dist = grid_bfs(grid, si, sj, '#');
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    ans = std::max(ans, dist[i][j]);
                }
            }
        }
    }
    std::cout << ans << std::endl;
}
