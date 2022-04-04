---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: src/graph/dijkstra.hpp
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
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"src/graph/dijkstra.hpp\"\
    \n#include <queue>\n\n\nstruct Edge {\n    int from, to;\n    long long cost;\n\
    \n    Edge(int to, long long cost) : from(-1), to(to), cost(cost) {}\n\n    Edge(int\
    \ from, int to, long long cost) : from(from), to(to), cost(cost) {}\n};\nusing\
    \ WeightedGraph = std::vector<std::vector<Edge>>;\n\n\nstd::vector<long long>\
    \ dijkstra(const WeightedGraph &g, int start) {\n    using P = std::pair<long\
    \ long, int>;\n    int n = g.size();\n    std::vector<long long> distance(n, 1LL\
    \ << 60);\n    distance[start] = 0LL;\n\n    std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> pq;\n    pq.emplace(0LL, start);\n    while (not pq.empty())\
    \ {\n        auto p = pq.top();\n        pq.pop();\n\n        int v = p.second;\n\
    \        if (distance[v] < p.first) continue;\n        for (const auto& e : g[v])\
    \ {\n            if (distance[e.to] > distance[v] + e.cost) {\n              \
    \  distance[e.to] = distance[v] + e.cost;\n                pq.emplace(distance[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return distance;\n}\n#line 6 \"\
    tests/aoj/GRL_1_A.test.cpp\"\n\n\nint main() {\n    int n, m, s;\n    std::cin\
    \ >> n >> m >> s;\n\n    WeightedGraph g(n);\n    for (int i = 0; i < m; i++)\
    \ {\n        int u, v, d;\n        std::cin >> u >> v >> d;\n        g[u].emplace_back(v,\
    \ d);\n    }\n    std::vector<long long> distance = dijkstra(g, s);\n\n    for\
    \ (const auto& dist : distance) {\n        if (dist == 1LL << 60) std::cout <<\
    \ \"INF\" << std::endl;\n        else std::cout << dist << std::endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../src/graph/dijkstra.hpp\"\
    \n\n\nint main() {\n    int n, m, s;\n    std::cin >> n >> m >> s;\n\n    WeightedGraph\
    \ g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v, d;\n        std::cin\
    \ >> u >> v >> d;\n        g[u].emplace_back(v, d);\n    }\n    std::vector<long\
    \ long> distance = dijkstra(g, s);\n\n    for (const auto& dist : distance) {\n\
    \        if (dist == 1LL << 60) std::cout << \"INF\" << std::endl;\n        else\
    \ std::cout << dist << std::endl;\n    }\n}\n"
  dependsOn:
  - src/graph/dijkstra.hpp
  isVerificationFile: true
  path: tests/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2022-04-05 00:38:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/GRL_1_A.test.cpp
- /verify/tests/aoj/GRL_1_A.test.cpp.html
title: tests/aoj/GRL_1_A.test.cpp
---
