---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/union-find/union-find-with-undo.hpp
    title: src/data-structure/union-find/union-find-with-undo.hpp
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: src/template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"tests/unittest/unionfind-with-undo.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n#line\
    \ 1 \"src/template/template.hpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <cstring>\n#include <deque>\n#include <iostream>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\n#define REP(i, n) for (int i = 0; i < (int)(n); ++ (i))\n#define\
    \ REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#line 2 \"src/data-structure/union-find/union-find-with-undo.hpp\"\
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
    \     undo();\n        }\n    }\n};\n#line 5 \"tests/unittest/unionfind-with-undo.test.cpp\"\
    \n\nint main() {\n    UnionFindWithUndo uf(4);\n\n    uf.merge(0, 1);\n    uf.merge(2,\
    \ 3);\n    assert(uf.same(0, 1));\n    assert(uf.same(2, 3));\n    assert(!uf.same(0,\
    \ 2));\n\n    uf.snapshot();\n    uf.merge(0, 2);\n    assert(uf.same(0, 1));\n\
    \    assert(uf.same(2, 3));\n    assert(uf.same(0, 2));\n\n    uf.rollback();\n\
    \    assert(uf.same(0, 1));\n    assert(uf.same(2, 3));\n    assert(!uf.same(0,\
    \ 2));\n\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../src/template/template.hpp\"\n#include \"../../src/data-structure/union-find/union-find-with-undo.hpp\"\
    \n\nint main() {\n    UnionFindWithUndo uf(4);\n\n    uf.merge(0, 1);\n    uf.merge(2,\
    \ 3);\n    assert(uf.same(0, 1));\n    assert(uf.same(2, 3));\n    assert(!uf.same(0,\
    \ 2));\n\n    uf.snapshot();\n    uf.merge(0, 2);\n    assert(uf.same(0, 1));\n\
    \    assert(uf.same(2, 3));\n    assert(uf.same(0, 2));\n\n    uf.rollback();\n\
    \    assert(uf.same(0, 1));\n    assert(uf.same(2, 3));\n    assert(!uf.same(0,\
    \ 2));\n\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/data-structure/union-find/union-find-with-undo.hpp
  isVerificationFile: true
  path: tests/unittest/unionfind-with-undo.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:53:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/unittest/unionfind-with-undo.test.cpp
layout: document
redirect_from:
- /verify/tests/unittest/unionfind-with-undo.test.cpp
- /verify/tests/unittest/unionfind-with-undo.test.cpp.html
title: tests/unittest/unionfind-with-undo.test.cpp
---
