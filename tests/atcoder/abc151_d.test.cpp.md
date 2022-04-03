---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/grid-bfs.hpp
    title: src/graph/grid-bfs.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc151/tasks/abc151_d
    links:
    - https://atcoder.jp/contests/abc151/tasks/abc151_d
  bundledCode: "#line 1 \"tests/atcoder/abc151_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc151/tasks/abc151_d\"\
    \n\n#include <iostream>\n#include <vector>\n#include <string>\n#line 3 \"src/graph/grid-bfs.hpp\"\
    \n#include <queue>\n\n\nconst int di[] = {0, 0, 1, -1};\nconst int dj[] = {1,\
    \ -1, 0, 0};\n\n\nstd::vector<std::vector<int>> grid_bfs(const std::vector<std::string>\
    \ &grid, int si, int sj, char wall = '#') {\n    const int h = grid.size();\n\
    \    const int w = grid[0].size();\n    std::vector<std::vector<int>> distance(h,\
    \ std::vector<int>(w, -1));\n    std::queue<std::pair<int, int>> que;\n\n    distance[si][sj]\
    \ = 0;\n    que.emplace(si, sj);\n    while (not que.empty()) {\n        auto\
    \ p = que.front();\n        que.pop();\n        for (int k = 0; k < 4; k++) {\n\
    \            int nxt_i = p.first + di[k];\n            int nxt_j = p.second +\
    \ dj[k];\n            if (nxt_i < 0 || h <= nxt_i) continue;\n            if (nxt_j\
    \ < 0 || w <= nxt_j) continue;\n            if (grid[nxt_i][nxt_j] == wall) continue;\n\
    \            if (distance[nxt_i][nxt_j] != -1) continue;\n            distance[nxt_i][nxt_j]\
    \ = distance[p.first][p.second] + 1;\n            que.emplace(nxt_i, nxt_j);\n\
    \        }\n    }\n    return distance;\n}\n#line 7 \"tests/atcoder/abc151_d.test.cpp\"\
    \n\n\n\nint main() {\n    int h, w;\n    std::cin >> h >> w;\n    std::vector<std::string>\
    \ grid(h);\n    for (auto& s : grid) { std::cin >> s; }\n\n    int ans = 0;\n\
    \    for (int si = 0; si < h; si++) {\n        for (int sj = 0; sj < w; sj++)\
    \ {\n            if (grid[si][sj] == '#') continue;\n            auto dist = grid_bfs(grid,\
    \ si, sj, '#');\n            for (int i = 0; i < h; i++) {\n                for\
    \ (int j = 0; j < w; j++) {\n                    ans = std::max(ans, dist[i][j]);\n\
    \                }\n            }\n        }\n    }\n    std::cout << ans << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc151/tasks/abc151_d\"\n\n\
    #include <iostream>\n#include <vector>\n#include <string>\n#include \"../../src/graph/grid-bfs.hpp\"\
    \n\n\n\nint main() {\n    int h, w;\n    std::cin >> h >> w;\n    std::vector<std::string>\
    \ grid(h);\n    for (auto& s : grid) { std::cin >> s; }\n\n    int ans = 0;\n\
    \    for (int si = 0; si < h; si++) {\n        for (int sj = 0; sj < w; sj++)\
    \ {\n            if (grid[si][sj] == '#') continue;\n            auto dist = grid_bfs(grid,\
    \ si, sj, '#');\n            for (int i = 0; i < h; i++) {\n                for\
    \ (int j = 0; j < w; j++) {\n                    ans = std::max(ans, dist[i][j]);\n\
    \                }\n            }\n        }\n    }\n    std::cout << ans << std::endl;\n\
    }\n"
  dependsOn:
  - src/graph/grid-bfs.hpp
  isVerificationFile: true
  path: tests/atcoder/abc151_d.test.cpp
  requiredBy: []
  timestamp: '2022-04-04 00:13:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/atcoder/abc151_d.test.cpp
layout: document
redirect_from:
- /verify/tests/atcoder/abc151_d.test.cpp
- /verify/tests/atcoder/abc151_d.test.cpp.html
title: tests/atcoder/abc151_d.test.cpp
---
