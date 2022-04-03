---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/warshall-floyd.hpp
    title: src/graph/warshall-floyd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"tests/aoj/GRL_1_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"src/graph/warshall-floyd.hpp\"\
    \n\n\nvoid warshall_floyd(std::vector<std::vector<long long>> &distance) {\n \
    \   int n = distance.size();\n    for (int k = 0; k < n; k++) {\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int j = 0; j < n; j++) {\n          \
    \      distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);\n\
    \            }\n        }\n    }\n}\n#line 6 \"tests/aoj/GRL_1_C.test.cpp\"\n\n\
    \nint main() {\n    const long long INF = 1LL << 60;\n    int n, m;\n    std::cin\
    \ >> n >> m;\n\n    std::vector<std::vector<long long>> distance(n, std::vector<long\
    \ long>(n, INF));\n    for (int v = 0; v < n; v++) {\n        distance[v][v] =\
    \ 0LL;\n    }\n    for (int i = 0; i < m; i++) {\n        int u, v;\n        long\
    \ long cost;\n        std::cin >> u >> v >> cost;\n        distance[u][v] = cost;\n\
    \    }\n\n    warshall_floyd(distance);\n    bool negative = false;\n    for (int\
    \ v = 0; v < n; v++) {\n        if (distance[v][v] < 0) negative = true;\n   \
    \ }\n\n    if (negative) std::cout << \"NEGATIVE CYCLE\" << std::endl;\n    else\
    \ {\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < n\
    \ - 1; j++) {\n                if (distance[i][j] > INF / 1'000) std::cout <<\
    \ \"INF\" << \" \";\n                else std::cout << distance[i][j] << \" \"\
    ;\n            }\n            if (distance[i][n - 1] > INF / 1'000) std::cout\
    \ << \"INF\" << std::endl;\n            else std::cout << distance[i][n - 1] <<\
    \ std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../src/graph/warshall-floyd.hpp\"\
    \n\n\nint main() {\n    const long long INF = 1LL << 60;\n    int n, m;\n    std::cin\
    \ >> n >> m;\n\n    std::vector<std::vector<long long>> distance(n, std::vector<long\
    \ long>(n, INF));\n    for (int v = 0; v < n; v++) {\n        distance[v][v] =\
    \ 0LL;\n    }\n    for (int i = 0; i < m; i++) {\n        int u, v;\n        long\
    \ long cost;\n        std::cin >> u >> v >> cost;\n        distance[u][v] = cost;\n\
    \    }\n\n    warshall_floyd(distance);\n    bool negative = false;\n    for (int\
    \ v = 0; v < n; v++) {\n        if (distance[v][v] < 0) negative = true;\n   \
    \ }\n\n    if (negative) std::cout << \"NEGATIVE CYCLE\" << std::endl;\n    else\
    \ {\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < n\
    \ - 1; j++) {\n                if (distance[i][j] > INF / 1'000) std::cout <<\
    \ \"INF\" << \" \";\n                else std::cout << distance[i][j] << \" \"\
    ;\n            }\n            if (distance[i][n - 1] > INF / 1'000) std::cout\
    \ << \"INF\" << std::endl;\n            else std::cout << distance[i][n - 1] <<\
    \ std::endl;\n        }\n    }\n}\n"
  dependsOn:
  - src/graph/warshall-floyd.hpp
  isVerificationFile: true
  path: tests/aoj/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2022-04-04 01:23:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/GRL_1_C.test.cpp
- /verify/tests/aoj/GRL_1_C.test.cpp.html
title: tests/aoj/GRL_1_C.test.cpp
---
