---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bfs-trace.hpp
    title: src/graph/bfs-trace.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"tests/aoj/ALDS1_11_C.bfs-trace.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\n\n\
    #include <iostream>\n#include <vector>\n#line 2 \"src/graph/bfs-trace.hpp\"\n\
    #include <queue>\n#include <algorithm>\nusing Graph = std::vector<std::vector<int>>;\n\
    \n\nstd::vector<int> bfs(const Graph &g, int start, std::vector<int> &parent)\
    \ {\n    const int n = g.size();\n\n    parent.resize(n, -1);\n    std::vector<int>\
    \ distance(n, -1);\n    std::queue<int> que;\n\n    distance[start] = 0;\n   \
    \ que.push(start);\n    while (not que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n\n        for (int nxt_v : g[v]) {\n            if (distance[nxt_v]\
    \ != -1) continue;\n            distance[nxt_v] = distance[v] + 1;\n         \
    \   parent[nxt_v] = v;\n            que.push(nxt_v);\n        }\n    }\n    return\
    \ distance;\n}\n\n\nstd::vector<int> trace_path(const std::vector<int> &parent,\
    \ int goal) {\n    std::vector<int> path(0);\n    for (int v = goal; v != -1;\
    \ v = parent[v]) {\n        path.push_back(v);\n    }\n    std::reverse(path.begin(),\
    \ path.end());\n    return path;\n}\n#line 6 \"tests/aoj/ALDS1_11_C.bfs-trace.test.cpp\"\
    \n\n\nint main() {\n    int n;\n    std::cin >> n;\n\n    Graph g(n);\n    for\
    \ (int i = 0; i < n; i++) {\n        int v, k, nxt_v;\n        std::cin >> v >>\
    \ k;\n        v -= 1;\n        for (int j = 0; j < k; j++) {\n            std::cin\
    \ >> nxt_v;\n            nxt_v -= 1;\n            g[v].push_back(nxt_v);\n   \
    \     }\n    }\n\n    std::vector<int> parent;\n    auto distance = bfs(g, 0,\
    \ parent);\n\n    for (int v = 0; v < n; v++) {\n        auto path = trace_path(parent,\
    \ v);\n        if (path[0] != 0) std::cout << v + 1 << \" \" << -1 << std::endl;\n\
    \        else std::cout << v + 1 << \" \" << (int)path.size() - 1<< std::endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../src/graph/bfs-trace.hpp\"\
    \n\n\nint main() {\n    int n;\n    std::cin >> n;\n\n    Graph g(n);\n    for\
    \ (int i = 0; i < n; i++) {\n        int v, k, nxt_v;\n        std::cin >> v >>\
    \ k;\n        v -= 1;\n        for (int j = 0; j < k; j++) {\n            std::cin\
    \ >> nxt_v;\n            nxt_v -= 1;\n            g[v].push_back(nxt_v);\n   \
    \     }\n    }\n\n    std::vector<int> parent;\n    auto distance = bfs(g, 0,\
    \ parent);\n\n    for (int v = 0; v < n; v++) {\n        auto path = trace_path(parent,\
    \ v);\n        if (path[0] != 0) std::cout << v + 1 << \" \" << -1 << std::endl;\n\
    \        else std::cout << v + 1 << \" \" << (int)path.size() - 1<< std::endl;\n\
    \    }\n}\n"
  dependsOn:
  - src/graph/bfs-trace.hpp
  isVerificationFile: true
  path: tests/aoj/ALDS1_11_C.bfs-trace.test.cpp
  requiredBy: []
  timestamp: '2022-04-13 00:33:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/ALDS1_11_C.bfs-trace.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/ALDS1_11_C.bfs-trace.test.cpp
- /verify/tests/aoj/ALDS1_11_C.bfs-trace.test.cpp.html
title: tests/aoj/ALDS1_11_C.bfs-trace.test.cpp
---
