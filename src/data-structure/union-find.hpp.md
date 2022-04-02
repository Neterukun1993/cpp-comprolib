---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/library_checker/unionfind.test.cpp
    title: tests/library_checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/union-find.hpp\"\n#include <vector>\n\
    \n\nstruct UnionFind {\n    std::vector<int> parent;\n    int cnt;\n\n    UnionFind(int\
    \ n) : parent(n, -1), cnt(n) {}\n\n    int root(int x) {\n        if (parent[x]\
    \ < 0) return x;\n        else return parent[x] = root(parent[x]);\n    }\n\n\
    \    bool merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return false;\n        if (parent[x] > parent[y]) std::swap(x,\
    \ y);\n        parent[x] += parent[y];\n        parent[y] = x;\n        cnt -=\
    \ 1;\n        return true;\n    }\n\n    int same(int x, int y) { return root(x)\
    \ == root(y); }\n\n    int size(int x) { return -parent[root(x)]; }\n\n    int\
    \ count() { return cnt; }\n};\n"
  code: "#include <vector>\n\n\nstruct UnionFind {\n    std::vector<int> parent;\n\
    \    int cnt;\n\n    UnionFind(int n) : parent(n, -1), cnt(n) {}\n\n    int root(int\
    \ x) {\n        if (parent[x] < 0) return x;\n        else return parent[x] =\
    \ root(parent[x]);\n    }\n\n    bool merge(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y) return false;\n        if (parent[x]\
    \ > parent[y]) std::swap(x, y);\n        parent[x] += parent[y];\n        parent[y]\
    \ = x;\n        cnt -= 1;\n        return true;\n    }\n\n    int same(int x,\
    \ int y) { return root(x) == root(y); }\n\n    int size(int x) { return -parent[root(x)];\
    \ }\n\n    int count() { return cnt; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/union-find.hpp
  requiredBy: []
  timestamp: '2022-04-03 01:52:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/library_checker/unionfind.test.cpp
documentation_of: src/data-structure/union-find.hpp
layout: document
redirect_from:
- /library/src/data-structure/union-find.hpp
- /library/src/data-structure/union-find.hpp.html
title: src/data-structure/union-find.hpp
---
