---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_1_C.test.cpp
    title: tests/aoj/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/warshall-floyd.hpp\"\n#include <vector>\n\n\n\
    void warshall_floyd(std::vector<std::vector<long long>> &distance) {\n    int\
    \ n = distance.size();\n    for (int k = 0; k < n; k++) {\n        for (int i\
    \ = 0; i < n; i++) {\n            for (int j = 0; j < n; j++) {\n            \
    \    distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);\n\
    \            }\n        }\n    }\n}\n"
  code: "#include <vector>\n\n\nvoid warshall_floyd(std::vector<std::vector<long long>>\
    \ &distance) {\n    int n = distance.size();\n    for (int k = 0; k < n; k++)\
    \ {\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < n;\
    \ j++) {\n                distance[i][j] = std::min(distance[i][j], distance[i][k]\
    \ + distance[k][j]);\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2022-04-04 01:23:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/GRL_1_C.test.cpp
documentation_of: src/graph/warshall-floyd.hpp
layout: document
redirect_from:
- /library/src/graph/warshall-floyd.hpp
- /library/src/graph/warshall-floyd.hpp.html
title: src/graph/warshall-floyd.hpp
---
