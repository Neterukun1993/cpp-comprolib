---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bfs.hpp
    title: src/graph/bfs.hpp
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
  bundledCode: "#line 1 \"tests/aoj/ALDS1_11_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"src/graph/bfs.hpp\"\n#include\
    \ <queue>\nusing Graph = std::vector<std::vector<int>>;\n\n\nstd::vector<int>\
    \ bfs(const Graph &g, int start) {\n    int n = g.size();\n    std::vector<int>\
    \ distance(n, -1);\n    std::queue<int> que;\n\n    distance[start] = 0;\n   \
    \ que.push(start);\n    while (not que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n\n        for (int nxt_v : g[v]) {\n            if (distance[nxt_v]\
    \ != -1) continue;\n            distance[nxt_v] = distance[v] + 1;\n         \
    \   que.push(nxt_v);\n        }\n    }\n    return distance;\n}\n#line 6 \"tests/aoj/ALDS1_11_C.test.cpp\"\
    \n\n\nint main() {\n    int n;\n    std::cin >> n;\n\n    Graph g(n);\n    for\
    \ (int i = 0; i < n; i++) {\n        int v, k, nxt_v;\n        std::cin >> v >>\
    \ k;\n        v -= 1;\n        for (int j = 0; j < k; j++) {\n            std::cin\
    \ >> nxt_v;\n            nxt_v -= 1;\n            g[v].push_back(nxt_v);\n   \
    \     }\n    }\n\n    std::vector<int> distance = bfs(g, 0);\n    for (int v =\
    \ 0; v < n; v++) {\n        std::cout << v + 1 << \" \" << distance[v] << std::endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../src/graph/bfs.hpp\"\
    \n\n\nint main() {\n    int n;\n    std::cin >> n;\n\n    Graph g(n);\n    for\
    \ (int i = 0; i < n; i++) {\n        int v, k, nxt_v;\n        std::cin >> v >>\
    \ k;\n        v -= 1;\n        for (int j = 0; j < k; j++) {\n            std::cin\
    \ >> nxt_v;\n            nxt_v -= 1;\n            g[v].push_back(nxt_v);\n   \
    \     }\n    }\n\n    std::vector<int> distance = bfs(g, 0);\n    for (int v =\
    \ 0; v < n; v++) {\n        std::cout << v + 1 << \" \" << distance[v] << std::endl;\n\
    \    }\n}\n"
  dependsOn:
  - src/graph/bfs.hpp
  isVerificationFile: true
  path: tests/aoj/ALDS1_11_C.test.cpp
  requiredBy: []
  timestamp: '2022-04-03 02:12:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/ALDS1_11_C.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/ALDS1_11_C.test.cpp
- /verify/tests/aoj/ALDS1_11_C.test.cpp.html
title: tests/aoj/ALDS1_11_C.test.cpp
---
