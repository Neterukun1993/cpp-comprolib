---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/minimum-spanning-tree/kruskal.hpp
    title: src/graph/minimum-spanning-tree/kruskal.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/misc/low-link.hpp
    title: src/graph/misc/low-link.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest-path/bellman-ford.hpp
    title: src/graph/shortest-path/bellman-ford.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest-path/bfs.hpp
    title: src/graph/shortest-path/bfs.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest-path/dijkstra.hpp
    title: src/graph/shortest-path/dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/ALDS1_11_C.test.cpp
    title: tests/aoj/ALDS1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_1_A.test.cpp
    title: tests/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_1_B.test.cpp
    title: tests/aoj/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_2_A.test.cpp
    title: tests/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_3_A.test.cpp
    title: tests/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_3_B.test.cpp
    title: tests/aoj/GRL_3_B.test.cpp
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
    \  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n\
    \    T cost;\n    int id;\n\n    Edge(int from, int to, T cost, int id) : from(from),\
    \ to(to), cost(cost), id(id) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n\
    \    bool is_directed;\n    int N, M;\n    std::vector<std::vector<Edge<T>>> adjacencies;\n\
    \n    Graph(bool is_directed = true) : is_directed(is_directed), N(0), M(0), adjacencies(0)\
    \ {}\n\n    Graph(int N, bool is_directed = true) : is_directed(is_directed),\
    \ N(N), M(0), adjacencies(N) {}\n\n    inline const std::vector<Edge<T>> &operator[]\
    \ (int k ) const {return adjacencies[k]; }\n\n    void init(int N_) {\n      \
    \  N = N_;\n        M = 0;\n        adjacencies.clear();\n        adjacencies.resize(N);\n\
    \    }\n\n    int size() const { return N; }\n\n    void add_edge(int from, int\
    \ to, T cost, int id) {\n        assert(0 <= from && from < N);\n        assert(0\
    \ <= to && to < N);\n        auto e = Edge<T>(from, to, cost, id);\n\n       \
    \ adjacencies[from].emplace_back(e);\n        if (!is_directed) {\n          \
    \  auto e2 = Edge<T>(to, from, cost, id);\n            adjacencies[to].emplace_back(e2);\n\
    \        }\n\n        M++;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/graph-template.hpp
  requiredBy:
  - src/graph/minimum-spanning-tree/kruskal.hpp
  - src/graph/shortest-path/bellman-ford.hpp
  - src/graph/shortest-path/bfs.hpp
  - src/graph/shortest-path/dijkstra.hpp
  - src/graph/misc/low-link.hpp
  timestamp: '2023-12-30 14:53:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/GRL_3_A.test.cpp
  - tests/aoj/GRL_1_A.test.cpp
  - tests/aoj/GRL_3_B.test.cpp
  - tests/aoj/GRL_2_A.test.cpp
  - tests/aoj/ALDS1_11_C.test.cpp
  - tests/aoj/GRL_1_B.test.cpp
documentation_of: src/graph/graph-template.hpp
layout: document
redirect_from:
- /library/src/graph/graph-template.hpp
- /library/src/graph/graph-template.hpp.html
title: src/graph/graph-template.hpp
---
