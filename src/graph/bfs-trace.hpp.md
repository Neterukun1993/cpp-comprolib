---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/ALDS1_11_C.bfs-trace.test.cpp
    title: tests/aoj/ALDS1_11_C.bfs-trace.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/bfs-trace.hpp\"\n#include <vector>\n#include <queue>\n\
    #include <algorithm>\nusing Graph = std::vector<std::vector<int>>;\n\n\nstd::vector<int>\
    \ bfs(const Graph &g, int start, std::vector<int> &parent) {\n    const int n\
    \ = g.size();\n\n    parent.resize(n, -1);\n    std::vector<int> distance(n, -1);\n\
    \    std::queue<int> que;\n\n    distance[start] = 0;\n    que.push(start);\n\
    \    while (not que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \n        for (int nxt_v : g[v]) {\n            if (distance[nxt_v] != -1) continue;\n\
    \            distance[nxt_v] = distance[v] + 1;\n            parent[nxt_v] = v;\n\
    \            que.push(nxt_v);\n        }\n    }\n    return distance;\n}\n\n\n\
    std::vector<int> trace_path(const std::vector<int> &parent, int goal) {\n    std::vector<int>\
    \ path(0);\n    for (int v = goal; v != -1; v = parent[v]) {\n        path.push_back(v);\n\
    \    }\n    std::reverse(path.begin(), path.end());\n    return path;\n}\n"
  code: "#include <vector>\n#include <queue>\n#include <algorithm>\nusing Graph =\
    \ std::vector<std::vector<int>>;\n\n\nstd::vector<int> bfs(const Graph &g, int\
    \ start, std::vector<int> &parent) {\n    const int n = g.size();\n\n    parent.resize(n,\
    \ -1);\n    std::vector<int> distance(n, -1);\n    std::queue<int> que;\n\n  \
    \  distance[start] = 0;\n    que.push(start);\n    while (not que.empty()) {\n\
    \        int v = que.front();\n        que.pop();\n\n        for (int nxt_v :\
    \ g[v]) {\n            if (distance[nxt_v] != -1) continue;\n            distance[nxt_v]\
    \ = distance[v] + 1;\n            parent[nxt_v] = v;\n            que.push(nxt_v);\n\
    \        }\n    }\n    return distance;\n}\n\n\nstd::vector<int> trace_path(const\
    \ std::vector<int> &parent, int goal) {\n    std::vector<int> path(0);\n    for\
    \ (int v = goal; v != -1; v = parent[v]) {\n        path.push_back(v);\n    }\n\
    \    std::reverse(path.begin(), path.end());\n    return path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bfs-trace.hpp
  requiredBy: []
  timestamp: '2022-04-13 00:33:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/ALDS1_11_C.bfs-trace.test.cpp
documentation_of: src/graph/bfs-trace.hpp
layout: document
redirect_from:
- /library/src/graph/bfs-trace.hpp
- /library/src/graph/bfs-trace.hpp.html
title: src/graph/bfs-trace.hpp
---
