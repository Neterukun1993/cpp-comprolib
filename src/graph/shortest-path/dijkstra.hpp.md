---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: src/graph/graph-template.hpp
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
  bundledCode: "#line 2 \"src/graph/graph-template.hpp\"\n\ntemplate <typename T>\n\
    struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\n    Edge(int from,\
    \ int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}\n};\n\n\
    template <typename T>\nstruct Graph {\n    bool is_directed;\n    int N, M;\n\
    \    std::vector<std::vector<Edge<T>>> adjacencies;\n\n    Graph(bool is_directed\
    \ = true) : is_directed(is_directed), N(0), M(0), adjacencies(0) {}\n\n    Graph(int\
    \ N, bool is_directed = true) : is_directed(is_directed), N(N), M(0), adjacencies(N)\
    \ {}\n\n    inline const std::vector<Edge<T>> &operator[] (int k ) const {return\
    \ adjacencies[k]; }\n\n    void init(int N_) {\n        N = N_;\n        M = 0;\n\
    \        adjacencies.clear();\n        adjacencies.resize(N);\n    }\n\n    int\
    \ size() const { return N; }\n\n    void add_edge(int from, int to, T cost, int\
    \ id) {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to\
    \ < N);\n        auto e = Edge<T>(from, to, cost, id);\n\n        adjacencies[from].emplace_back(e);\n\
    \        if (!is_directed) {\n            auto e2 = Edge<T>(to, from, cost, id);\n\
    \            adjacencies[to].emplace_back(e2);\n        }\n\n        M++;\n  \
    \  }\n};\n#line 3 \"src/graph/shortest-path/dijkstra.hpp\"\n\ntemplate <typename\
    \ T>\nvoid dijkstra(const Graph<T> &g, const int start, std::vector<T> &distance)\
    \ {\n    assert(g.size() == (int)distance.size());\n\n    constexpr T INF = std::numeric_limits<T>::max();\n\
    \    std::fill(distance.begin(), distance.end(), INF);\n    distance[start] =\
    \ 0;\n\n    using P = std::pair<T, int>;\n    static std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> pq;\n    pq.emplace(distance[start], start);\n\n    while (not\
    \ pq.empty()) {\n        const auto p = pq.top();\n        pq.pop();\n\n     \
    \   const int v = p.second;\n        if (distance[v] < p.first) continue;\n  \
    \      for (const auto& e : g[v]) {\n            if (distance[e.to] > distance[v]\
    \ + e.cost) {\n                distance[e.to] = distance[v] + e.cost;\n      \
    \          pq.emplace(distance[e.to], e.to);\n            }\n        }\n    }\n\
    }\n"
  code: "#pragma once\n#include \"../graph-template.hpp\"\n\ntemplate <typename T>\n\
    void dijkstra(const Graph<T> &g, const int start, std::vector<T> &distance) {\n\
    \    assert(g.size() == (int)distance.size());\n\n    constexpr T INF = std::numeric_limits<T>::max();\n\
    \    std::fill(distance.begin(), distance.end(), INF);\n    distance[start] =\
    \ 0;\n\n    using P = std::pair<T, int>;\n    static std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> pq;\n    pq.emplace(distance[start], start);\n\n    while (not\
    \ pq.empty()) {\n        const auto p = pq.top();\n        pq.pop();\n\n     \
    \   const int v = p.second;\n        if (distance[v] < p.first) continue;\n  \
    \      for (const auto& e : g[v]) {\n            if (distance[e.to] > distance[v]\
    \ + e.cost) {\n                distance[e.to] = distance[v] + e.cost;\n      \
    \          pq.emplace(distance[e.to], e.to);\n            }\n        }\n    }\n\
    }\n"
  dependsOn:
  - src/graph/graph-template.hpp
  isVerificationFile: false
  path: src/graph/shortest-path/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-12-30 14:53:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/GRL_1_A.test.cpp
documentation_of: src/graph/shortest-path/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/shortest-path/dijkstra.hpp
- /library/src/graph/shortest-path/dijkstra.hpp.html
title: src/graph/shortest-path/dijkstra.hpp
---
