---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/union-find.hpp
    title: src/data-structure/union-find.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/kruskal.hpp
    title: src/graph/kruskal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"tests/aoj/GRL_2_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"src/graph/kruskal.hpp\"\n\
    #include <algorithm>\n#line 2 \"src/data-structure/union-find.hpp\"\n\n\nstruct\
    \ UnionFind {\n    std::vector<int> parent;\n    int cnt;\n\n    UnionFind(int\
    \ n) : parent(n, -1), cnt(n) {}\n\n    int root(int x) {\n        if (parent[x]\
    \ < 0) return x;\n        else return parent[x] = root(parent[x]);\n    }\n\n\
    \    bool merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return false;\n        if (parent[x] > parent[y]) std::swap(x,\
    \ y);\n        parent[x] += parent[y];\n        parent[y] = x;\n        cnt -=\
    \ 1;\n        return true;\n    }\n\n    int same(int x, int y) { return root(x)\
    \ == root(y); }\n\n    int size(int x) { return -parent[root(x)]; }\n\n    int\
    \ count() { return cnt; }\n};\n#line 4 \"src/graph/kruskal.hpp\"\n\n\nstruct Edge\
    \ {\n    int from, to;\n    long long cost;\n\n    Edge(int to, long long cost)\
    \ : from(-1), to(to), cost(cost) {}\n\n    Edge(int from, int to, long long cost)\
    \ : from(from), to(to), cost(cost) {}\n};\n\n\nlong long kruskal(int n, std::vector<Edge>\
    \ edges) {\n    std::sort(edges.begin(), edges.end(), [](const Edge &a, const\
    \ Edge &b) {\n        return a.cost < b.cost;\n    });\n    UnionFind uf(n);\n\
    \    long long total_cost = 0LL;\n    for (const auto& e : edges) {\n        if\
    \ (not uf.same(e.from, e.to)) {\n            uf.merge(e.from, e.to);\n       \
    \     total_cost += e.cost;\n        }\n    }\n    return total_cost;\n}\n#line\
    \ 6 \"tests/aoj/GRL_2_A.test.cpp\"\n\n\nint main() {\n    int n, m;\n    std::cin\
    \ >> n >> m;\n    std::vector<Edge> edges;\n    for (int i = 0; i < m; i++) {\n\
    \        int u, v;\n        long long cost;\n        std::cin >> u >> v >> cost;\n\
    \        edges.emplace_back(u, v, cost);\n    }\n    auto ans = kruskal(n, edges);\n\
    \    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../src/graph/kruskal.hpp\"\
    \n\n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<Edge>\
    \ edges;\n    for (int i = 0; i < m; i++) {\n        int u, v;\n        long long\
    \ cost;\n        std::cin >> u >> v >> cost;\n        edges.emplace_back(u, v,\
    \ cost);\n    }\n    auto ans = kruskal(n, edges);\n    std::cout << ans << std::endl;\n\
    }\n"
  dependsOn:
  - src/graph/kruskal.hpp
  - src/data-structure/union-find.hpp
  isVerificationFile: true
  path: tests/aoj/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-04-05 00:37:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/GRL_2_A.test.cpp
- /verify/tests/aoj/GRL_2_A.test.cpp.html
title: tests/aoj/GRL_2_A.test.cpp
---
