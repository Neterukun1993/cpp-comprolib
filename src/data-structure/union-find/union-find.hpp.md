---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/minimum-spanning-tree/kruskal.hpp
    title: src/graph/minimum-spanning-tree/kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_2_A.test.cpp
    title: tests/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/library-checker/unionfind.test.cpp
    title: tests/library-checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/union-find/union-find.hpp\"\n\nstruct\
    \ UnionFind {\n    std::vector<int> parent;\n    int cnt;\n\n    UnionFind(int\
    \ n) : parent(n, -1), cnt(n) {}\n\n    void clear() {\n        std::fill(parent.begin(),\
    \ parent.end(), -1);\n        cnt = (int)parent.size();\n    }\n\n    int root(int\
    \ x) {\n        if (parent[x] < 0) return x;\n        else return parent[x] =\
    \ root(parent[x]);\n    }\n\n    bool merge(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y) return false;\n        if (parent[x]\
    \ > parent[y]) std::swap(x, y);\n        parent[x] += parent[y];\n        parent[y]\
    \ = x;\n        cnt -= 1;\n        return true;\n    }\n\n    int same(int x,\
    \ int y) { return root(x) == root(y); }\n\n    int size(int x) { return -parent[root(x)];\
    \ }\n\n    int count() { return cnt; }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n    std::vector<int> parent;\n    int\
    \ cnt;\n\n    UnionFind(int n) : parent(n, -1), cnt(n) {}\n\n    void clear()\
    \ {\n        std::fill(parent.begin(), parent.end(), -1);\n        cnt = (int)parent.size();\n\
    \    }\n\n    int root(int x) {\n        if (parent[x] < 0) return x;\n      \
    \  else return parent[x] = root(parent[x]);\n    }\n\n    bool merge(int x, int\
    \ y) {\n        x = root(x);\n        y = root(y);\n        if (x == y) return\
    \ false;\n        if (parent[x] > parent[y]) std::swap(x, y);\n        parent[x]\
    \ += parent[y];\n        parent[y] = x;\n        cnt -= 1;\n        return true;\n\
    \    }\n\n    int same(int x, int y) { return root(x) == root(y); }\n\n    int\
    \ size(int x) { return -parent[root(x)]; }\n\n    int count() { return cnt; }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/union-find/union-find.hpp
  requiredBy:
  - src/graph/minimum-spanning-tree/kruskal.hpp
  timestamp: '2024-01-03 04:55:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/library-checker/unionfind.test.cpp
  - tests/aoj/GRL_2_A.test.cpp
documentation_of: src/data-structure/union-find/union-find.hpp
layout: document
redirect_from:
- /library/src/data-structure/union-find/union-find.hpp
- /library/src/data-structure/union-find/union-find.hpp.html
title: src/data-structure/union-find/union-find.hpp
---
