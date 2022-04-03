---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/atcoder/abc151_d.test.cpp
    title: tests/atcoder/abc151_d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/grid-bfs.hpp\"\n#include <vector>\n#include <string>\n\
    #include <queue>\n\n\nconst int di[] = {0, 0, 1, -1};\nconst int dj[] = {1, -1,\
    \ 0, 0};\n\n\nstd::vector<std::vector<int>> grid_bfs(const std::vector<std::string>\
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
    \        }\n    }\n    return distance;\n}\n"
  code: "#include <vector>\n#include <string>\n#include <queue>\n\n\nconst int di[]\
    \ = {0, 0, 1, -1};\nconst int dj[] = {1, -1, 0, 0};\n\n\nstd::vector<std::vector<int>>\
    \ grid_bfs(const std::vector<std::string> &grid, int si, int sj, char wall = '#')\
    \ {\n    const int h = grid.size();\n    const int w = grid[0].size();\n    std::vector<std::vector<int>>\
    \ distance(h, std::vector<int>(w, -1));\n    std::queue<std::pair<int, int>> que;\n\
    \n    distance[si][sj] = 0;\n    que.emplace(si, sj);\n    while (not que.empty())\
    \ {\n        auto p = que.front();\n        que.pop();\n        for (int k = 0;\
    \ k < 4; k++) {\n            int nxt_i = p.first + di[k];\n            int nxt_j\
    \ = p.second + dj[k];\n            if (nxt_i < 0 || h <= nxt_i) continue;\n  \
    \          if (nxt_j < 0 || w <= nxt_j) continue;\n            if (grid[nxt_i][nxt_j]\
    \ == wall) continue;\n            if (distance[nxt_i][nxt_j] != -1) continue;\n\
    \            distance[nxt_i][nxt_j] = distance[p.first][p.second] + 1;\n     \
    \       que.emplace(nxt_i, nxt_j);\n        }\n    }\n    return distance;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/grid-bfs.hpp
  requiredBy: []
  timestamp: '2022-04-04 00:13:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/atcoder/abc151_d.test.cpp
documentation_of: src/graph/grid-bfs.hpp
layout: document
redirect_from:
- /library/src/graph/grid-bfs.hpp
- /library/src/graph/grid-bfs.hpp.html
title: src/graph/grid-bfs.hpp
---
