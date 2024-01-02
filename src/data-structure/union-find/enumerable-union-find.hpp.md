---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/library-checker/enumerable-union-find.test.cpp
    title: tests/library-checker/enumerable-union-find.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/unittest/enumerable-union-find.test.cpp
    title: tests/unittest/enumerable-union-find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/union-find/enumerable-union-find.hpp\"\
    \n\nstruct EnumerableUnionFind {\n    std::vector<int> parent;\n    std::vector<int>\
    \ next;\n\n    EnumerableUnionFind(int n) : parent(n, -1), next(n) {\n       \
    \ for (int i = 0; i < n; i++) { next[i] = i; }\n    }\n\n    void clear() {\n\
    \        std::fill(parent.begin(), parent.end(), -1);\n        for (int i = 0;\
    \ i < (int)parent.size(); i++) { next[i] = i; }\n    }\n\n    int root(int x)\
    \ {\n        if (parent[x] < 0) return x;\n        else return parent[x] = root(parent[x]);\n\
    \    }\n\n    bool merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return false;\n        if (parent[x] > parent[y]) std::swap(x,\
    \ y);\n        parent[x] += parent[y];\n        parent[y] = x;\n        std::swap(next[x],\
    \ next[y]);\n        return true;\n    }\n\n    int same(int x, int y) { return\
    \ root(x) == root(y); }\n\n    int size(int x) { return -parent[root(x)]; }\n\n\
    \    std::vector<int> group(int x) {\n        std::vector<int> result;\n     \
    \   int init = x;\n        while (true) {\n            result.push_back(x);\n\
    \            x = next[x];\n            if (x == init) break;\n        }\n    \
    \    return result;\n    }\n};\n"
  code: "#pragma once\n\nstruct EnumerableUnionFind {\n    std::vector<int> parent;\n\
    \    std::vector<int> next;\n\n    EnumerableUnionFind(int n) : parent(n, -1),\
    \ next(n) {\n        for (int i = 0; i < n; i++) { next[i] = i; }\n    }\n\n \
    \   void clear() {\n        std::fill(parent.begin(), parent.end(), -1);\n   \
    \     for (int i = 0; i < (int)parent.size(); i++) { next[i] = i; }\n    }\n\n\
    \    int root(int x) {\n        if (parent[x] < 0) return x;\n        else return\
    \ parent[x] = root(parent[x]);\n    }\n\n    bool merge(int x, int y) {\n    \
    \    x = root(x);\n        y = root(y);\n        if (x == y) return false;\n \
    \       if (parent[x] > parent[y]) std::swap(x, y);\n        parent[x] += parent[y];\n\
    \        parent[y] = x;\n        std::swap(next[x], next[y]);\n        return\
    \ true;\n    }\n\n    int same(int x, int y) { return root(x) == root(y); }\n\n\
    \    int size(int x) { return -parent[root(x)]; }\n\n    std::vector<int> group(int\
    \ x) {\n        std::vector<int> result;\n        int init = x;\n        while\
    \ (true) {\n            result.push_back(x);\n            x = next[x];\n     \
    \       if (x == init) break;\n        }\n        return result;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/union-find/enumerable-union-find.hpp
  requiredBy: []
  timestamp: '2024-01-03 05:22:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/unittest/enumerable-union-find.test.cpp
  - tests/library-checker/enumerable-union-find.test.cpp
documentation_of: src/data-structure/union-find/enumerable-union-find.hpp
layout: document
redirect_from:
- /library/src/data-structure/union-find/enumerable-union-find.hpp
- /library/src/data-structure/union-find/enumerable-union-find.hpp.html
title: src/data-structure/union-find/enumerable-union-find.hpp
---
