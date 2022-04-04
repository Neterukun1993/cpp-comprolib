---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/union-find.hpp
    title: src/data-structure/union-find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_2_A.test.cpp
    title: tests/aoj/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/kruskal.hpp\"\n#include <vector>\n#include <algorithm>\n\
    #line 2 \"src/data-structure/union-find.hpp\"\n\n\nstruct UnionFind {\n    std::vector<int>\
    \ parent;\n    int cnt;\n\n    UnionFind(int n) : parent(n, -1), cnt(n) {}\n\n\
    \    int root(int x) {\n        if (parent[x] < 0) return x;\n        else return\
    \ parent[x] = root(parent[x]);\n    }\n\n    bool merge(int x, int y) {\n    \
    \    x = root(x);\n        y = root(y);\n        if (x == y) return false;\n \
    \       if (parent[x] > parent[y]) std::swap(x, y);\n        parent[x] += parent[y];\n\
    \        parent[y] = x;\n        cnt -= 1;\n        return true;\n    }\n\n  \
    \  int same(int x, int y) { return root(x) == root(y); }\n\n    int size(int x)\
    \ { return -parent[root(x)]; }\n\n    int count() { return cnt; }\n};\n#line 4\
    \ \"src/graph/kruskal.hpp\"\n\n\nstruct Edge {\n    int from, to;\n    long long\
    \ cost;\n\n    Edge(int to, long long cost) : from(-1), to(to), cost(cost) {}\n\
    \n    Edge(int from, int to, long long cost) : from(from), to(to), cost(cost)\
    \ {}\n};\n\n\nlong long kruskal(int n, std::vector<Edge> edges) {\n    std::sort(edges.begin(),\
    \ edges.end(), [](const Edge &a, const Edge &b) {\n        return a.cost < b.cost;\n\
    \    });\n    UnionFind uf(n);\n    long long total_cost = 0LL;\n    for (const\
    \ auto& e : edges) {\n        if (not uf.same(e.from, e.to)) {\n            uf.merge(e.from,\
    \ e.to);\n            total_cost += e.cost;\n        }\n    }\n    return total_cost;\n\
    }\n"
  code: "#include <vector>\n#include <algorithm>\n#include \"../../src/data-structure/union-find.hpp\"\
    \n\n\nstruct Edge {\n    int from, to;\n    long long cost;\n\n    Edge(int to,\
    \ long long cost) : from(-1), to(to), cost(cost) {}\n\n    Edge(int from, int\
    \ to, long long cost) : from(from), to(to), cost(cost) {}\n};\n\n\nlong long kruskal(int\
    \ n, std::vector<Edge> edges) {\n    std::sort(edges.begin(), edges.end(), [](const\
    \ Edge &a, const Edge &b) {\n        return a.cost < b.cost;\n    });\n    UnionFind\
    \ uf(n);\n    long long total_cost = 0LL;\n    for (const auto& e : edges) {\n\
    \        if (not uf.same(e.from, e.to)) {\n            uf.merge(e.from, e.to);\n\
    \            total_cost += e.cost;\n        }\n    }\n    return total_cost;\n\
    }\n"
  dependsOn:
  - src/data-structure/union-find.hpp
  isVerificationFile: false
  path: src/graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-04-05 00:37:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/GRL_2_A.test.cpp
documentation_of: src/graph/kruskal.hpp
layout: document
redirect_from:
- /library/src/graph/kruskal.hpp
- /library/src/graph/kruskal.hpp.html
title: src/graph/kruskal.hpp
---
