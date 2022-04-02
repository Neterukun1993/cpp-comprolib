---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/ALDS1_11_C.test.cpp
    title: tests/aoj/ALDS1_11_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/bfs.hpp\"\n#include <vector>\n#include <queue>\n\
    using Graph = std::vector<std::vector<int>>;\n\n\nstd::vector<int> bfs(const Graph\
    \ &g, int start) {\n    int n = g.size();\n    std::vector<int> distance(n, -1);\n\
    \    std::queue<int> que;\n\n    distance[start] = 0;\n    que.push(start);\n\
    \    while (not que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \n        for (int nxt_v : g[v]) {\n            if (distance[nxt_v] != -1) continue;\n\
    \            distance[nxt_v] = distance[v] + 1;\n            que.push(nxt_v);\n\
    \        }\n    }\n    return distance;\n}\n"
  code: "#include <vector>\n#include <queue>\nusing Graph = std::vector<std::vector<int>>;\n\
    \n\nstd::vector<int> bfs(const Graph &g, int start) {\n    int n = g.size();\n\
    \    std::vector<int> distance(n, -1);\n    std::queue<int> que;\n\n    distance[start]\
    \ = 0;\n    que.push(start);\n    while (not que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n\n        for (int nxt_v : g[v]) {\n            if (distance[nxt_v]\
    \ != -1) continue;\n            distance[nxt_v] = distance[v] + 1;\n         \
    \   que.push(nxt_v);\n        }\n    }\n    return distance;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bfs.hpp
  requiredBy: []
  timestamp: '2022-04-03 02:12:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/ALDS1_11_C.test.cpp
documentation_of: src/graph/bfs.hpp
layout: document
redirect_from:
- /library/src/graph/bfs.hpp
- /library/src/graph/bfs.hpp.html
title: src/graph/bfs.hpp
---
