---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/library-checker/unionfind.test.cpp
    title: tests/library-checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/union-find/union-find.hpp\"\n\nstruct UnionFind {\n\
    \    std::vector<int> parent;\n    int cnt;\n\n    UnionFind(int n) : parent(n,\
    \ -1), cnt(n) {}\n\n    int root(int x) {\n        if (parent[x] < 0) return x;\n\
    \        else return parent[x] = root(parent[x]);\n    }\n\n    bool merge(int\
    \ x, int y) {\n        x = root(x);\n        y = root(y);\n        if (x == y)\
    \ return false;\n        if (parent[x] > parent[y]) std::swap(x, y);\n       \
    \ parent[x] += parent[y];\n        parent[y] = x;\n        cnt -= 1;\n       \
    \ return true;\n    }\n\n    int same(int x, int y) { return root(x) == root(y);\
    \ }\n\n    int size(int x) { return -parent[root(x)]; }\n\n    int count() { return\
    \ cnt; }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n    std::vector<int> parent;\n    int\
    \ cnt;\n\n    UnionFind(int n) : parent(n, -1), cnt(n) {}\n\n    int root(int\
    \ x) {\n        if (parent[x] < 0) return x;\n        else return parent[x] =\
    \ root(parent[x]);\n    }\n\n    bool merge(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y) return false;\n        if (parent[x]\
    \ > parent[y]) std::swap(x, y);\n        parent[x] += parent[y];\n        parent[y]\
    \ = x;\n        cnt -= 1;\n        return true;\n    }\n\n    int same(int x,\
    \ int y) { return root(x) == root(y); }\n\n    int size(int x) { return -parent[root(x)];\
    \ }\n\n    int count() { return cnt; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/union-find/union-find.hpp
  requiredBy: []
  timestamp: '2023-12-30 02:35:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/library-checker/unionfind.test.cpp
documentation_of: src/union-find/union-find.hpp
layout: document
redirect_from:
- /library/src/union-find/union-find.hpp
- /library/src/union-find/union-find.hpp.html
title: src/union-find/union-find.hpp
---
