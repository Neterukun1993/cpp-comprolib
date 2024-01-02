---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/library-checker/unionfind-with-undo.test.cpp
    title: tests/library-checker/unionfind-with-undo.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/unittest/unionfind-with-undo.test.cpp
    title: tests/unittest/unionfind-with-undo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/union-find/union-find-with-undo.hpp\"\
    \n\nstruct UnionFindWithUndo {\n    std::vector<int> parent;\n    std::vector<std::pair<int,\
    \ int>> history;\n    int snap;\n\n    UnionFindWithUndo(int n) : parent(n, -1),\
    \ history(0), snap(0) {}\n\n    void clear() {\n        std::fill(parent.begin(),\
    \ parent.end(), -1);\n        history.clear();\n        snap = 0;\n    }\n\n \
    \   int root(int x) {\n        if (parent[x] < 0) return x;\n        else return\
    \ root(parent[x]);\n    }\n\n    bool merge(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        history.emplace_back(x, parent[x]);\n        history.emplace_back(y,\
    \ parent[y]);\n        if (x == y) return false;\n        if (parent[x] > parent[y])\
    \ std::swap(x, y);\n        parent[x] += parent[y];\n        parent[y] = x;\n\
    \        return true;\n    }\n\n    int same(int x, int y) { return root(x) ==\
    \ root(y); }\n\n    int size(int x) { return -parent[root(x)]; }\n\n    bool undo()\
    \ {\n        if (history.empty()) return false;\n        parent[history.back().first]\
    \ = history.back().second;\n        history.pop_back();\n        parent[history.back().first]\
    \ = history.back().second;\n        history.pop_back();\n        return true;\n\
    \    }\n\n    void snapshot() {\n        snap = (int)history.size();\n    }\n\n\
    \    void rollback() {\n        while ((int)history.size() > snap) {\n       \
    \     undo();\n        }\n    }\n};\n"
  code: "#pragma once\n\nstruct UnionFindWithUndo {\n    std::vector<int> parent;\n\
    \    std::vector<std::pair<int, int>> history;\n    int snap;\n\n    UnionFindWithUndo(int\
    \ n) : parent(n, -1), history(0), snap(0) {}\n\n    void clear() {\n        std::fill(parent.begin(),\
    \ parent.end(), -1);\n        history.clear();\n        snap = 0;\n    }\n\n \
    \   int root(int x) {\n        if (parent[x] < 0) return x;\n        else return\
    \ root(parent[x]);\n    }\n\n    bool merge(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        history.emplace_back(x, parent[x]);\n        history.emplace_back(y,\
    \ parent[y]);\n        if (x == y) return false;\n        if (parent[x] > parent[y])\
    \ std::swap(x, y);\n        parent[x] += parent[y];\n        parent[y] = x;\n\
    \        return true;\n    }\n\n    int same(int x, int y) { return root(x) ==\
    \ root(y); }\n\n    int size(int x) { return -parent[root(x)]; }\n\n    bool undo()\
    \ {\n        if (history.empty()) return false;\n        parent[history.back().first]\
    \ = history.back().second;\n        history.pop_back();\n        parent[history.back().first]\
    \ = history.back().second;\n        history.pop_back();\n        return true;\n\
    \    }\n\n    void snapshot() {\n        snap = (int)history.size();\n    }\n\n\
    \    void rollback() {\n        while ((int)history.size() > snap) {\n       \
    \     undo();\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/union-find/union-find-with-undo.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:53:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/unittest/unionfind-with-undo.test.cpp
  - tests/library-checker/unionfind-with-undo.test.cpp
documentation_of: src/data-structure/union-find/union-find-with-undo.hpp
layout: document
redirect_from:
- /library/src/data-structure/union-find/union-find-with-undo.hpp
- /library/src/data-structure/union-find/union-find-with-undo.hpp.html
title: src/data-structure/union-find/union-find-with-undo.hpp
---
