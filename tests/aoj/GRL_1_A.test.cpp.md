---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: src/graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest-path/dijkstra.hpp
    title: src/graph/shortest-path/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: src/template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"tests/aoj/GRL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#line 1 \"src/template/template.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <cstring>\n#include <deque>\n#include <iostream>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\n#define REP(i, n) for (int i = 0; i < (int)(n); ++ (i))\n#define\
    \ REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#line 2 \"src/graph/graph-template.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cost;\n   \
    \ int id;\n\n    Edge(int from, int to, T cost, int id) : from(from), to(to),\
    \ cost(cost), id(id) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n    bool\
    \ is_directed;\n    int N, M;\n    std::vector<std::vector<Edge<T>>> adjacencies;\n\
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
    \        }\n\n        M++;\n    }\n};\n#line 3 \"src/graph/shortest-path/dijkstra.hpp\"\
    \n\ntemplate <typename T>\nvoid dijkstra(const Graph<T> &g, const int start, std::vector<T>\
    \ &distance) {\n    assert(g.size() == (int)distance.size());\n\n    constexpr\
    \ T INF = std::numeric_limits<T>::max();\n    std::fill(distance.begin(), distance.end(),\
    \ INF);\n    distance[start] = 0;\n\n    using P = std::pair<T, int>;\n    static\
    \ std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n    pq.emplace(distance[start],\
    \ start);\n\n    while (not pq.empty()) {\n        const auto p = pq.top();\n\
    \        pq.pop();\n\n        const int v = p.second;\n        if (distance[v]\
    \ < p.first) continue;\n        for (const auto& e : g[v]) {\n            if (distance[e.to]\
    \ > distance[v] + e.cost) {\n                distance[e.to] = distance[v] + e.cost;\n\
    \                pq.emplace(distance[e.to], e.to);\n            }\n        }\n\
    \    }\n}\n#line 5 \"tests/aoj/GRL_1_A.test.cpp\"\n\nint main() {\n    int n,\
    \ m, s;\n    std::cin >> n >> m >> s;\n\n    Graph<long long> g(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int u, v;\n        long long d;\n        std::cin\
    \ >> u >> v >> d;\n        g.add_edge(u, v, d, i);\n    }\n    std::vector<long\
    \ long> distance(n);\n    dijkstra(g, s, distance);\n\n    long long INF = std::numeric_limits<long\
    \ long>::max();\n    for (const auto& dist : distance) {\n        if (dist ==\
    \ INF) std::cout << \"INF\" << std::endl;\n        else std::cout << dist << std::endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../src/template/template.hpp\"\n#include \"../../src/graph/shortest-path/dijkstra.hpp\"\
    \n\nint main() {\n    int n, m, s;\n    std::cin >> n >> m >> s;\n\n    Graph<long\
    \ long> g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v;\n        long\
    \ long d;\n        std::cin >> u >> v >> d;\n        g.add_edge(u, v, d, i);\n\
    \    }\n    std::vector<long long> distance(n);\n    dijkstra(g, s, distance);\n\
    \n    long long INF = std::numeric_limits<long long>::max();\n    for (const auto&\
    \ dist : distance) {\n        if (dist == INF) std::cout << \"INF\" << std::endl;\n\
    \        else std::cout << dist << std::endl;\n    }\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/graph/shortest-path/dijkstra.hpp
  - src/graph/graph-template.hpp
  isVerificationFile: true
  path: tests/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-12-30 14:53:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/GRL_1_A.test.cpp
- /verify/tests/aoj/GRL_1_A.test.cpp.html
title: tests/aoj/GRL_1_A.test.cpp
---
