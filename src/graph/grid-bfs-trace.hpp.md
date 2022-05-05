---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/atcoder/abc151_d_grid-bfs-trace.test.cpp
    title: tests/atcoder/abc151_d_grid-bfs-trace.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/grid-bfs-trace.hpp\"\n#include <vector>\n#include\
    \ <string>\n#include <queue>\n#include <algorithm>\n#include <iostream>\n\n\n\
    const std::string direction = \"RLDU\";\nconst int di[] = {0, 0, 1, -1};\nconst\
    \ int dj[] = {1, -1, 0, 0};\n\n\nstd::vector<std::vector<int>> grid_bfs(const\
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
    \        }\n    }\n    return route;\n}\n"
  code: "#include <vector>\n#include <string>\n#include <queue>\n#include <algorithm>\n\
    #include <iostream>\n\n\nconst std::string direction = \"RLDU\";\nconst int di[]\
    \ = {0, 0, 1, -1};\nconst int dj[] = {1, -1, 0, 0};\n\n\nstd::vector<std::vector<int>>\
    \ grid_bfs(const std::vector<std::string> &grid, int si, int sj,\n           \
    \                            std::vector<std::vector<std::pair<int, int>>> &parent,\
    \ char wall = '#') {\n    const int h = grid.size();\n    const int w = grid[0].size();\n\
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
    \        }\n    }\n    return route;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/grid-bfs-trace.hpp
  requiredBy: []
  timestamp: '2022-05-05 16:08:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/atcoder/abc151_d_grid-bfs-trace.test.cpp
documentation_of: src/graph/grid-bfs-trace.hpp
layout: document
redirect_from:
- /library/src/graph/grid-bfs-trace.hpp
- /library/src/graph/grid-bfs-trace.hpp.html
title: src/graph/grid-bfs-trace.hpp
---
