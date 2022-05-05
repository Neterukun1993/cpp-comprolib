---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/grid-bfs-trace.hpp
    title: src/graph/grid-bfs-trace.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc151/tasks/abc151_d
    links:
    - https://atcoder.jp/contests/abc151/tasks/abc151_d
  bundledCode: "#line 1 \"tests/atcoder/abc151_d_grid-bfs-trace.test.cpp\"\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc151/tasks/abc151_d\"\n\n#include <iostream>\n\
    #include <vector>\n#include <string>\n#include <algorithm>\n#include <cassert>\n\
    #line 3 \"src/graph/grid-bfs-trace.hpp\"\n#include <queue>\n#line 6 \"src/graph/grid-bfs-trace.hpp\"\
    \n\n\nconst std::string direction = \"RLDU\";\nconst int di[] = {0, 0, 1, -1};\n\
    const int dj[] = {1, -1, 0, 0};\n\n\nstd::vector<std::vector<int>> grid_bfs(const\
    \ std::vector<std::string> &grid, int si, int sj,\n                          \
    \             std::vector<std::vector<std::pair<int, int>>> &parent, char wall\
    \ = '#') {\n    const int h = grid.size();\n    const int w = grid[0].size();\n\
    \n    parent.resize(h, std::vector<std::pair<int, int>>(w, {-1, -1}));\n    std::vector<std::vector<int>>\
    \ distance(h, std::vector<int>(w, -1));\n    std::queue<std::pair<int, int>> que;\n\
    \n    distance[si][sj] = 0;\n    que.emplace(si, sj);\n    while (not que.empty())\
    \ {\n        auto p = que.front();\n        que.pop();\n        for (int k = 0;\
    \ k < 4; k++) {\n            int nxt_i = p.first + di[k];\n            int nxt_j\
    \ = p.second + dj[k];\n            if (nxt_i < 0 || h <= nxt_i) continue;\n  \
    \          if (nxt_j < 0 || w <= nxt_j) continue;\n            if (grid[nxt_i][nxt_j]\
    \ == wall) continue;\n            if (distance[nxt_i][nxt_j] != -1) continue;\n\
    \            distance[nxt_i][nxt_j] = distance[p.first][p.second] + 1;\n     \
    \       parent[nxt_i][nxt_j] = {p.first, p.second};\n            que.emplace(nxt_i,\
    \ nxt_j);\n        }\n    }\n    return distance;\n}\n\n\nstd::vector<std::pair<int,\
    \ int>> trace_path(const std::vector<std::vector<std::pair<int, int>>> &parent,\
    \ int gi, int gj) {\n    std::vector<std::pair<int, int>> path;\n    std::pair<int,\
    \ int> v = {gi, gj};\n    while (v.first != -1 && v.second != -1) {\n        path.push_back(v);\n\
    \        v = parent[v.first][v.second];\n    }\n    std::reverse(path.begin(),\
    \ path.end());\n    return path;\n}\n\n\nstd::string trace_route(const std::vector<std::vector<std::pair<int,\
    \ int>>> &parent, int gi, int gj) {\n    auto path = trace_path(parent, gi, gj);\n\
    \    std::string route;\n    for (int i = 0; i < (int)path.size() - 1; i++) {\n\
    \        for (int k = 0; k < 4; k++) {\n            int nxt_i = path[i].first\
    \ + di[k];\n            int nxt_j = path[i].second + dj[k];\n            if (nxt_i\
    \ == path[i + 1].first && nxt_j == path[i + 1].second) route.push_back(direction[k]);\n\
    \        }\n    }\n    return route;\n}\n#line 9 \"tests/atcoder/abc151_d_grid-bfs-trace.test.cpp\"\
    \n\n\nbool is_correct_route(std::string &route, std::vector<std::string> &grid,\
    \ int si, int sj, int gi, int gj) {\n    bool res = true;\n    if (grid[si][sj]\
    \ == '#') res = false;\n    for (const auto& dire : route) {\n        if (dire\
    \ == 'R') sj += 1;\n        if (dire == 'L') sj -= 1;\n        if (dire == 'D')\
    \ si += 1;\n        if (dire == 'U') si -= 1;\n        if (grid[si][sj] == '#')\
    \ res = false;\n    }\n    if (si != gi || sj != gj) res = false;\n    return\
    \ res;\n}\n\n\nint main() {\n    int h, w;\n    std::cin >> h >> w;\n    std::vector<std::string>\
    \ grid(h);\n    for (auto& s : grid) { std::cin >> s; }\n\n    int ans = 0;\n\
    \    for (int si = 0; si < h; si++) {\n        for (int sj = 0; sj < w; sj++)\
    \ {\n            if (grid[si][sj] == '#') continue;\n            std::vector<std::vector<std::pair<int,\
    \ int>>> parent;\n            auto dist = grid_bfs(grid, si, sj, parent, '#');\n\
    \            for (int i = 0; i < h; i++) {\n                for (int j = 0; j\
    \ < w; j++) {\n                    if (dist[i][j] != -1) {\n                 \
    \       auto route = trace_route(parent, i, j);\n                        assert(is_correct_route(route,\
    \ grid, si, sj, i, j));\n                        ans = std::max(ans, (int)route.size());\n\
    \                    }\n                }\n            }\n        }\n    }\n \
    \   std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc151/tasks/abc151_d\"\n\n\
    #include <iostream>\n#include <vector>\n#include <string>\n#include <algorithm>\n\
    #include <cassert>\n#include \"../../src/graph/grid-bfs-trace.hpp\"\n\n\nbool\
    \ is_correct_route(std::string &route, std::vector<std::string> &grid, int si,\
    \ int sj, int gi, int gj) {\n    bool res = true;\n    if (grid[si][sj] == '#')\
    \ res = false;\n    for (const auto& dire : route) {\n        if (dire == 'R')\
    \ sj += 1;\n        if (dire == 'L') sj -= 1;\n        if (dire == 'D') si +=\
    \ 1;\n        if (dire == 'U') si -= 1;\n        if (grid[si][sj] == '#') res\
    \ = false;\n    }\n    if (si != gi || sj != gj) res = false;\n    return res;\n\
    }\n\n\nint main() {\n    int h, w;\n    std::cin >> h >> w;\n    std::vector<std::string>\
    \ grid(h);\n    for (auto& s : grid) { std::cin >> s; }\n\n    int ans = 0;\n\
    \    for (int si = 0; si < h; si++) {\n        for (int sj = 0; sj < w; sj++)\
    \ {\n            if (grid[si][sj] == '#') continue;\n            std::vector<std::vector<std::pair<int,\
    \ int>>> parent;\n            auto dist = grid_bfs(grid, si, sj, parent, '#');\n\
    \            for (int i = 0; i < h; i++) {\n                for (int j = 0; j\
    \ < w; j++) {\n                    if (dist[i][j] != -1) {\n                 \
    \       auto route = trace_route(parent, i, j);\n                        assert(is_correct_route(route,\
    \ grid, si, sj, i, j));\n                        ans = std::max(ans, (int)route.size());\n\
    \                    }\n                }\n            }\n        }\n    }\n \
    \   std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - src/graph/grid-bfs-trace.hpp
  isVerificationFile: true
  path: tests/atcoder/abc151_d_grid-bfs-trace.test.cpp
  requiredBy: []
  timestamp: '2022-05-05 16:08:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/atcoder/abc151_d_grid-bfs-trace.test.cpp
layout: document
redirect_from:
- /verify/tests/atcoder/abc151_d_grid-bfs-trace.test.cpp
- /verify/tests/atcoder/abc151_d_grid-bfs-trace.test.cpp.html
title: tests/atcoder/abc151_d_grid-bfs-trace.test.cpp
---
