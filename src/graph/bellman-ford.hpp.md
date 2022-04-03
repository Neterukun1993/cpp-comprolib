---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_1_B.test.cpp
    title: tests/aoj/GRL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/bellman-ford.hpp\"\n#include <iostream>\n#include\
    \ <vector>\n\n\nstruct Edge {\n    int to;\n    long long cost;\n    Edge(int\
    \ to_, long long cost_) : to(to_), cost(cost_) {}\n};\nusing WeightedGraph = std::vector<std::vector<Edge>>;\n\
    \n\nstd::pair<bool, std::vector<long long>> bellman_ford(const WeightedGraph &g,\
    \ int start) {\n    int n = g.size();\n    long long INF = 1LL << 60;\n    std::vector<long\
    \ long> distance(n, INF);\n    distance[start] = 0LL;\n\n    for (int i = 0; i\
    \ < n; i++) {\n        bool update = false;\n        for (int v = 0; v < n; v++)\
    \ {\n            for (auto& e: g[v]) {\n                if (distance[v] != INF\
    \ && distance[e.to] > distance[v] + e.cost) {\n                    distance[e.to]\
    \ = distance[v] + e.cost;\n                    update = true;\n              \
    \  }\n            }\n        }\n        if (not update) {\n            return\
    \ {true, distance};\n        }\n    }\n    return {false, distance};\n}\n"
  code: "#include <iostream>\n#include <vector>\n\n\nstruct Edge {\n    int to;\n\
    \    long long cost;\n    Edge(int to_, long long cost_) : to(to_), cost(cost_)\
    \ {}\n};\nusing WeightedGraph = std::vector<std::vector<Edge>>;\n\n\nstd::pair<bool,\
    \ std::vector<long long>> bellman_ford(const WeightedGraph &g, int start) {\n\
    \    int n = g.size();\n    long long INF = 1LL << 60;\n    std::vector<long long>\
    \ distance(n, INF);\n    distance[start] = 0LL;\n\n    for (int i = 0; i < n;\
    \ i++) {\n        bool update = false;\n        for (int v = 0; v < n; v++) {\n\
    \            for (auto& e: g[v]) {\n                if (distance[v] != INF &&\
    \ distance[e.to] > distance[v] + e.cost) {\n                    distance[e.to]\
    \ = distance[v] + e.cost;\n                    update = true;\n              \
    \  }\n            }\n        }\n        if (not update) {\n            return\
    \ {true, distance};\n        }\n    }\n    return {false, distance};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bellman-ford.hpp
  requiredBy: []
  timestamp: '2022-04-04 00:50:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/GRL_1_B.test.cpp
documentation_of: src/graph/bellman-ford.hpp
layout: document
redirect_from:
- /library/src/graph/bellman-ford.hpp
- /library/src/graph/bellman-ford.hpp.html
title: src/graph/bellman-ford.hpp
---
