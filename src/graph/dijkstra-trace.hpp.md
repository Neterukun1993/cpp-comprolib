---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/library_checker/shortest_path.test.cpp
    title: tests/library_checker/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/dijkstra-trace.hpp\"\n#include <vector>\n#include\
    \ <queue>\n#include <algorithm>\n\n\nstruct Edge {\n    int from, to;\n    long\
    \ long cost;\n\n    Edge(int to, long long cost) : from(-1), to(to), cost(cost)\
    \ {}\n\n    Edge(int from, int to, long long cost) : from(from), to(to), cost(cost)\
    \ {}\n};\nusing WeightedGraph = std::vector<std::vector<Edge>>;\n\n\nstd::vector<long\
    \ long> dijkstra(const WeightedGraph &g, int start, std::vector<int> &parent)\
    \ {\n    using P = std::pair<long long, int>;\n    const int n = g.size();\n\n\
    \    parent.resize(n, -1);\n    std::vector<long long> distance(n, 1LL << 60);\n\
    \    distance[start] = 0LL;\n\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n    pq.emplace(0LL, start);\n\n    while (not pq.empty()) {\n        auto\
    \ p = pq.top();\n        pq.pop();\n\n        int v = p.second;\n        if (distance[v]\
    \ < p.first) continue;\n\n        for (const auto& e : g[v]) {\n            if\
    \ (distance[e.to] > distance[v] + e.cost) {\n                distance[e.to] =\
    \ distance[v] + e.cost;\n                parent[e.to] = v;\n                pq.emplace(distance[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return distance;\n}\n\n\nstd::vector<int>\
    \ trace_path(const std::vector<int> &parent, int goal) {\n    std::vector<int>\
    \ path;\n    for (int v = goal; v != -1; v = parent[v]) {\n        path.push_back(v);\n\
    \    }\n    std::reverse(path.begin(), path.end());\n    return path;\n}\n"
  code: "#include <vector>\n#include <queue>\n#include <algorithm>\n\n\nstruct Edge\
    \ {\n    int from, to;\n    long long cost;\n\n    Edge(int to, long long cost)\
    \ : from(-1), to(to), cost(cost) {}\n\n    Edge(int from, int to, long long cost)\
    \ : from(from), to(to), cost(cost) {}\n};\nusing WeightedGraph = std::vector<std::vector<Edge>>;\n\
    \n\nstd::vector<long long> dijkstra(const WeightedGraph &g, int start, std::vector<int>\
    \ &parent) {\n    using P = std::pair<long long, int>;\n    const int n = g.size();\n\
    \n    parent.resize(n, -1);\n    std::vector<long long> distance(n, 1LL << 60);\n\
    \    distance[start] = 0LL;\n\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n    pq.emplace(0LL, start);\n\n    while (not pq.empty()) {\n        auto\
    \ p = pq.top();\n        pq.pop();\n\n        int v = p.second;\n        if (distance[v]\
    \ < p.first) continue;\n\n        for (const auto& e : g[v]) {\n            if\
    \ (distance[e.to] > distance[v] + e.cost) {\n                distance[e.to] =\
    \ distance[v] + e.cost;\n                parent[e.to] = v;\n                pq.emplace(distance[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return distance;\n}\n\n\nstd::vector<int>\
    \ trace_path(const std::vector<int> &parent, int goal) {\n    std::vector<int>\
    \ path;\n    for (int v = goal; v != -1; v = parent[v]) {\n        path.push_back(v);\n\
    \    }\n    std::reverse(path.begin(), path.end());\n    return path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra-trace.hpp
  requiredBy: []
  timestamp: '2022-04-13 00:13:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/library_checker/shortest_path.test.cpp
documentation_of: src/graph/dijkstra-trace.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra-trace.hpp
- /library/src/graph/dijkstra-trace.hpp.html
title: src/graph/dijkstra-trace.hpp
---
