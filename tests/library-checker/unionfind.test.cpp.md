---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/union-find/union-find.hpp
    title: src/data-structure/union-find/union-find.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"tests/library-checker/unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"src/template/template.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <cstdint>\n#include <cstring>\n\
    #include <deque>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <vector>\n\n#define REP(i, n) for (int i =\
    \ 0; i < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#line 2 \"src/data-structure/union-find/union-find.hpp\"\n\nstruct\
    \ UnionFind {\n    std::vector<int> parent;\n    int cnt;\n\n    UnionFind(int\
    \ n) : parent(n, -1), cnt(n) {}\n\n    int root(int x) {\n        if (parent[x]\
    \ < 0) return x;\n        else return parent[x] = root(parent[x]);\n    }\n\n\
    \    bool merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return false;\n        if (parent[x] > parent[y]) std::swap(x,\
    \ y);\n        parent[x] += parent[y];\n        parent[y] = x;\n        cnt -=\
    \ 1;\n        return true;\n    }\n\n    int same(int x, int y) { return root(x)\
    \ == root(y); }\n\n    int size(int x) { return -parent[root(x)]; }\n\n    int\
    \ count() { return cnt; }\n};\n#line 5 \"tests/library-checker/unionfind.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n    UnionFind uf(n);\n\
    \n    for (int i = 0; i < q; i++) {\n        int flag, u, v;\n        std::cin\
    \ >> flag >> u >> v;\n        if (flag) {\n            std::cout << ((uf.same(u,\
    \ v)) ? 1 : 0) << std::endl;\n        } else {\n            uf.merge(u, v);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../src/template/template.hpp\"\n#include \"../../src/data-structure/union-find/union-find.hpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n    UnionFind uf(n);\n\
    \n    for (int i = 0; i < q; i++) {\n        int flag, u, v;\n        std::cin\
    \ >> flag >> u >> v;\n        if (flag) {\n            std::cout << ((uf.same(u,\
    \ v)) ? 1 : 0) << std::endl;\n        } else {\n            uf.merge(u, v);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/data-structure/union-find/union-find.hpp
  isVerificationFile: true
  path: tests/library-checker/unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-12-30 12:42:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/library-checker/unionfind.test.cpp
layout: document
redirect_from:
- /verify/tests/library-checker/unionfind.test.cpp
- /verify/tests/library-checker/unionfind.test.cpp.html
title: tests/library-checker/unionfind.test.cpp
---
