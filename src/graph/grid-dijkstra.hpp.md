---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yukicoder/0020.test.cpp
    title: tests/yukicoder/0020.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/grid-dijkstra.hpp\"\n#include <tuple>\n#include\
    \ <vector>\n#include <queue>\n\n\nconst int di[] = {0, 0, 1, -1};\nconst int dj[]\
    \ = {1, -1, 0, 0};\n\n\nstd::vector<std::vector<long long>> dijkstra(const std::vector<std::vector<long\
    \ long>> &grid, int si, int sj) {\n    using P = std::tuple<long long, int, int>;\n\
    \    int h = grid.size();\n    int w = grid[0].size();\n\n    std::vector<std::vector<long\
    \ long>> distance(h, std::vector<long long>(w, 1LL << 60));\n    distance[si][sj]\
    \ = 0LL;\n\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n\
    \    pq.emplace(0LL, si, sj);\n\n    while (not pq.empty()) {\n        auto p\
    \ = pq.top();\n        pq.pop();\n\n        int& i = std::get<1>(p);\n       \
    \ int& j = std::get<2>(p);\n        if (distance[i][j] < std::get<0>(p)) continue;\n\
    \n        for (int k = 0; k < 4; k++) {\n            int nxt_i = i + di[k];\n\
    \            int nxt_j = j + dj[k];\n            if (nxt_i < 0 || h <= nxt_i)\
    \ continue;\n            if (nxt_j < 0 || w <= nxt_j) continue;\n            if\
    \ (distance[nxt_i][nxt_j] > distance[i][j] + grid[nxt_i][nxt_j]) {\n         \
    \       distance[nxt_i][nxt_j] = distance[i][j] + grid[nxt_i][nxt_j];\n      \
    \          pq.emplace(distance[nxt_i][nxt_j], nxt_i, nxt_j);\n            }\n\
    \        }\n    }\n    return distance;\n}\n\n"
  code: "#include <tuple>\n#include <vector>\n#include <queue>\n\n\nconst int di[]\
    \ = {0, 0, 1, -1};\nconst int dj[] = {1, -1, 0, 0};\n\n\nstd::vector<std::vector<long\
    \ long>> dijkstra(const std::vector<std::vector<long long>> &grid, int si, int\
    \ sj) {\n    using P = std::tuple<long long, int, int>;\n    int h = grid.size();\n\
    \    int w = grid[0].size();\n\n    std::vector<std::vector<long long>> distance(h,\
    \ std::vector<long long>(w, 1LL << 60));\n    distance[si][sj] = 0LL;\n\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0LL, si, sj);\n\n    while\
    \ (not pq.empty()) {\n        auto p = pq.top();\n        pq.pop();\n\n      \
    \  int& i = std::get<1>(p);\n        int& j = std::get<2>(p);\n        if (distance[i][j]\
    \ < std::get<0>(p)) continue;\n\n        for (int k = 0; k < 4; k++) {\n     \
    \       int nxt_i = i + di[k];\n            int nxt_j = j + dj[k];\n         \
    \   if (nxt_i < 0 || h <= nxt_i) continue;\n            if (nxt_j < 0 || w <=\
    \ nxt_j) continue;\n            if (distance[nxt_i][nxt_j] > distance[i][j] +\
    \ grid[nxt_i][nxt_j]) {\n                distance[nxt_i][nxt_j] = distance[i][j]\
    \ + grid[nxt_i][nxt_j];\n                pq.emplace(distance[nxt_i][nxt_j], nxt_i,\
    \ nxt_j);\n            }\n        }\n    }\n    return distance;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/grid-dijkstra.hpp
  requiredBy: []
  timestamp: '2022-04-12 21:18:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yukicoder/0020.test.cpp
documentation_of: src/graph/grid-dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/grid-dijkstra.hpp
- /library/src/graph/grid-dijkstra.hpp.html
title: src/graph/grid-dijkstra.hpp
---
