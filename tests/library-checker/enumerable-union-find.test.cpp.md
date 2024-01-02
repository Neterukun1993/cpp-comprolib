---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/union-find/enumerable-union-find.hpp
    title: src/data-structure/union-find/enumerable-union-find.hpp
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
  bundledCode: "#line 1 \"tests/library-checker/enumerable-union-find.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"src/template/template.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <cstdint>\n#include <cstring>\n\
    #include <deque>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <vector>\n\n#define REP(i, n) for (int i =\
    \ 0; i < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#line 2 \"src/data-structure/union-find/enumerable-union-find.hpp\"\
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
    \    return result;\n    }\n};\n#line 5 \"tests/library-checker/enumerable-union-find.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n    EnumerableUnionFind\
    \ uf(n);\n\n    for (int i = 0; i < q; i++) {\n        int flag, u, v;\n     \
    \   std::cin >> flag >> u >> v;\n        if (flag) {\n            std::cout <<\
    \ ((uf.same(u, v)) ? 1 : 0) << std::endl;\n        } else {\n            uf.merge(u,\
    \ v);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../src/template/template.hpp\"\n#include \"../../src/data-structure/union-find/enumerable-union-find.hpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n    EnumerableUnionFind\
    \ uf(n);\n\n    for (int i = 0; i < q; i++) {\n        int flag, u, v;\n     \
    \   std::cin >> flag >> u >> v;\n        if (flag) {\n            std::cout <<\
    \ ((uf.same(u, v)) ? 1 : 0) << std::endl;\n        } else {\n            uf.merge(u,\
    \ v);\n        }\n    }\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/data-structure/union-find/enumerable-union-find.hpp
  isVerificationFile: true
  path: tests/library-checker/enumerable-union-find.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 05:22:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/library-checker/enumerable-union-find.test.cpp
layout: document
redirect_from:
- /verify/tests/library-checker/enumerable-union-find.test.cpp
- /verify/tests/library-checker/enumerable-union-find.test.cpp.html
title: tests/library-checker/enumerable-union-find.test.cpp
---
