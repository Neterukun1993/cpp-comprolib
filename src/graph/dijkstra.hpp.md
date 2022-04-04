---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_1_A.test.cpp
    title: tests/aoj/GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/dijkstra.hpp\"\n#include <vector>\n#include <queue>\n\
    \n\nstruct Edge {\n    int from, to;\n    long long cost;\n\n    Edge(int to,\
    \ long long cost) : from(-1), to(to), cost(cost) {}\n\n    Edge(int from, int\
    \ to, long long cost) : from(from), to(to), cost(cost) {}\n};\nusing WeightedGraph\
    \ = std::vector<std::vector<Edge>>;\n\n\nstd::vector<long long> dijkstra(const\
    \ WeightedGraph &g, int start) {\n    using P = std::pair<long long, int>;\n \
    \   int n = g.size();\n    std::vector<long long> distance(n, 1LL << 60);\n  \
    \  distance[start] = 0LL;\n\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n    pq.emplace(0LL, start);\n    while (not pq.empty()) {\n        auto\
    \ p = pq.top();\n        pq.pop();\n\n        int v = p.second;\n        if (distance[v]\
    \ < p.first) continue;\n        for (const auto& e : g[v]) {\n            if (distance[e.to]\
    \ > distance[v] + e.cost) {\n                distance[e.to] = distance[v] + e.cost;\n\
    \                pq.emplace(distance[e.to], e.to);\n            }\n        }\n\
    \    }\n    return distance;\n}\n"
  code: "#include <vector>\n#include <queue>\n\n\nstruct Edge {\n    int from, to;\n\
    \    long long cost;\n\n    Edge(int to, long long cost) : from(-1), to(to), cost(cost)\
    \ {}\n\n    Edge(int from, int to, long long cost) : from(from), to(to), cost(cost)\
    \ {}\n};\nusing WeightedGraph = std::vector<std::vector<Edge>>;\n\n\nstd::vector<long\
    \ long> dijkstra(const WeightedGraph &g, int start) {\n    using P = std::pair<long\
    \ long, int>;\n    int n = g.size();\n    std::vector<long long> distance(n, 1LL\
    \ << 60);\n    distance[start] = 0LL;\n\n    std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> pq;\n    pq.emplace(0LL, start);\n    while (not pq.empty())\
    \ {\n        auto p = pq.top();\n        pq.pop();\n\n        int v = p.second;\n\
    \        if (distance[v] < p.first) continue;\n        for (const auto& e : g[v])\
    \ {\n            if (distance[e.to] > distance[v] + e.cost) {\n              \
    \  distance[e.to] = distance[v] + e.cost;\n                pq.emplace(distance[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return distance;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-04-05 00:38:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/GRL_1_A.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: src/graph/dijkstra.hpp
---
