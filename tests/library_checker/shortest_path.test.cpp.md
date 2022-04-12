---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra-trace.hpp
    title: src/graph/dijkstra-trace.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"tests/library_checker/shortest_path.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <iostream>\n\
    #include <vector>\n#line 2 \"src/graph/dijkstra-trace.hpp\"\n#include <queue>\n\
    #include <algorithm>\n\n\nstruct Edge {\n    int from, to;\n    long long cost;\n\
    \n    Edge(int to, long long cost) : from(-1), to(to), cost(cost) {}\n\n    Edge(int\
    \ from, int to, long long cost) : from(from), to(to), cost(cost) {}\n};\nusing\
    \ WeightedGraph = std::vector<std::vector<Edge>>;\n\n\nstd::vector<long long>\
    \ dijkstra(const WeightedGraph &g, int start, std::vector<int> &parent) {\n  \
    \  using P = std::pair<long long, int>;\n    const int n = g.size();\n\n    parent.resize(n,\
    \ -1);\n    std::vector<long long> distance(n, 1LL << 60);\n    distance[start]\
    \ = 0LL;\n\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n\
    \    pq.emplace(0LL, start);\n\n    while (not pq.empty()) {\n        auto p =\
    \ pq.top();\n        pq.pop();\n\n        int v = p.second;\n        if (distance[v]\
    \ < p.first) continue;\n\n        for (const auto& e : g[v]) {\n            if\
    \ (distance[e.to] > distance[v] + e.cost) {\n                distance[e.to] =\
    \ distance[v] + e.cost;\n                parent[e.to] = v;\n                pq.emplace(distance[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return distance;\n}\n\n\nstd::vector<int>\
    \ trace_path(const std::vector<int> &parent, int goal) {\n    std::vector<int>\
    \ path;\n    for (int v = goal; v != -1; v = parent[v]) {\n        path.push_back(v);\n\
    \    }\n    std::reverse(path.begin(), path.end());\n    return path;\n}\n#line\
    \ 6 \"tests/library_checker/shortest_path.test.cpp\"\n\n\nint main() {\n    int\
    \ n, m, s, t;\n    std::cin >> n >> m >> s >> t;\n\n    WeightedGraph graph(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v;\n        long long cost;\n\
    \        std::cin >> u >> v >> cost;\n        graph[u].emplace_back(v, cost);\n\
    \    }\n\n    std::vector<int> parent;\n    auto distance = dijkstra(graph, s,\
    \ parent);\n    auto path = trace_path(parent, t);\n\n    if (distance[t] == 1LL\
    \ << 60) {\n        std::cout << -1 << std::endl;\n        return 0;\n    }\n\
    \    std::cout << distance[t] << \" \" << (int)path.size() - 1 << std::endl;\n\
    \    for (int i = 0; i < (int)path.size() - 1; i++) {\n        std::cout << path[i]\
    \ << \" \" << path[i + 1] << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include \"../../src/graph/dijkstra-trace.hpp\"\
    \n\n\nint main() {\n    int n, m, s, t;\n    std::cin >> n >> m >> s >> t;\n\n\
    \    WeightedGraph graph(n);\n    for (int i = 0; i < m; i++) {\n        int u,\
    \ v;\n        long long cost;\n        std::cin >> u >> v >> cost;\n        graph[u].emplace_back(v,\
    \ cost);\n    }\n\n    std::vector<int> parent;\n    auto distance = dijkstra(graph,\
    \ s, parent);\n    auto path = trace_path(parent, t);\n\n    if (distance[t] ==\
    \ 1LL << 60) {\n        std::cout << -1 << std::endl;\n        return 0;\n   \
    \ }\n    std::cout << distance[t] << \" \" << (int)path.size() - 1 << std::endl;\n\
    \    for (int i = 0; i < (int)path.size() - 1; i++) {\n        std::cout << path[i]\
    \ << \" \" << path[i + 1] << std::endl;\n    }\n}\n"
  dependsOn:
  - src/graph/dijkstra-trace.hpp
  isVerificationFile: true
  path: tests/library_checker/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2022-04-13 00:13:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/library_checker/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/tests/library_checker/shortest_path.test.cpp
- /verify/tests/library_checker/shortest_path.test.cpp.html
title: tests/library_checker/shortest_path.test.cpp
---
