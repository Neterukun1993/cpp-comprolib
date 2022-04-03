---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bellman-ford.hpp
    title: src/graph/bellman-ford.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"tests/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"src/graph/bellman-ford.hpp\"\
    \n\n\nstruct Edge {\n    int to;\n    long long cost;\n    Edge(int to_, long\
    \ long cost_) : to(to_), cost(cost_) {}\n};\nusing WeightedGraph = std::vector<std::vector<Edge>>;\n\
    \n\nstd::pair<bool, std::vector<long long>> bellman_ford(const WeightedGraph &g,\
    \ int start) {\n    int n = g.size();\n    long long INF = 1LL << 60;\n    std::vector<long\
    \ long> distance(n, INF);\n    distance[start] = 0LL;\n\n    for (int i = 0; i\
    \ < n; i++) {\n        bool update = false;\n        for (int v = 0; v < n; v++)\
    \ {\n            for (auto& e: g[v]) {\n                if (distance[v] != INF\
    \ && distance[e.to] > distance[v] + e.cost) {\n                    distance[e.to]\
    \ = distance[v] + e.cost;\n                    update = true;\n              \
    \  }\n            }\n        }\n        if (not update) {\n            return\
    \ {true, distance};\n        }\n    }\n    return {false, distance};\n}\n#line\
    \ 6 \"tests/aoj/GRL_1_B.test.cpp\"\n\n\nint main() {\n    int n, m, s;\n    std::cin\
    \ >> n >> m >> s;\n\n    WeightedGraph g(n);\n    for (int i = 0; i < m; i++)\
    \ {\n        int u, v, d;\n        std::cin >> u >> v >> d;\n        g[u].emplace_back(v,\
    \ d);\n    }\n    auto result = bellman_ford(g, s);\n    if (not result.first)\
    \ std::cout << \"NEGATIVE CYCLE\" << std::endl;\n    else {\n        for (const\
    \ auto& val : result.second) {\n            if (val == 1LL << 60) std::cout <<\
    \ \"INF\" << std::endl;\n            else std::cout << val << std::endl;\n   \
    \     }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../src/graph/bellman-ford.hpp\"\
    \n\n\nint main() {\n    int n, m, s;\n    std::cin >> n >> m >> s;\n\n    WeightedGraph\
    \ g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v, d;\n        std::cin\
    \ >> u >> v >> d;\n        g[u].emplace_back(v, d);\n    }\n    auto result =\
    \ bellman_ford(g, s);\n    if (not result.first) std::cout << \"NEGATIVE CYCLE\"\
    \ << std::endl;\n    else {\n        for (const auto& val : result.second) {\n\
    \            if (val == 1LL << 60) std::cout << \"INF\" << std::endl;\n      \
    \      else std::cout << val << std::endl;\n        }\n    }\n}\n"
  dependsOn:
  - src/graph/bellman-ford.hpp
  isVerificationFile: true
  path: tests/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2022-04-04 00:50:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/GRL_1_B.test.cpp
- /verify/tests/aoj/GRL_1_B.test.cpp.html
title: tests/aoj/GRL_1_B.test.cpp
---
