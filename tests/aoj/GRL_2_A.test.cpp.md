---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/union-find/union-find.hpp
    title: src/data-structure/union-find/union-find.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: src/graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/minimum-spanning-tree/kruskal.hpp
    title: src/graph/minimum-spanning-tree/kruskal.hpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"tests/aoj/GRL_2_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#line 1 \"src/template/template.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <cstring>\n#include <deque>\n#include <iostream>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\n#define REP(i, n) for (int i = 0; i < (int)(n); ++ (i))\n#define\
    \ REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#line 2 \"src/graph/graph-template.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cost;\n   \
    \ int id;\n\n    Edge(int from, int to, T cost, int id) : from(from), to(to),\
    \ cost(cost), id(id) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n    bool\
    \ is_directed;\n    int N, M;\n    std::vector<std::vector<Edge<T>>> adjacencies;\n\
    \n    Graph(bool is_directed = true) : is_directed(is_directed), N(0), M(0), adjacencies(0)\
    \ {}\n\n    Graph(int N, bool is_directed = true) : is_directed(is_directed),\
    \ N(N), M(0), adjacencies(N) {}\n\n    inline const std::vector<Edge<T>> &operator[]\
    \ (int k ) const {return adjacencies[k]; }\n\n    void init(int N_) {\n      \
    \  N = N_;\n        M = 0;\n        adjacencies.clear();\n        adjacencies.resize(N);\n\
    \    }\n\n    int size() const { return N; }\n\n    void add_edge(int from, int\
    \ to, T cost, int id) {\n        assert(0 <= from && from < N);\n        assert(0\
    \ <= to && to < N);\n        auto e = Edge<T>(from, to, cost, id);\n\n       \
    \ adjacencies[from].emplace_back(e);\n        if (!is_directed) {\n          \
    \  auto e2 = Edge<T>(to, from, cost, id);\n            adjacencies[to].emplace_back(e2);\n\
    \        }\n\n        M++;\n    }\n};\n#line 2 \"src/data-structure/union-find/union-find.hpp\"\
    \n\nstruct UnionFind {\n    std::vector<int> parent;\n    int cnt;\n\n    UnionFind(int\
    \ n) : parent(n, -1), cnt(n) {}\n\n    int root(int x) {\n        if (parent[x]\
    \ < 0) return x;\n        else return parent[x] = root(parent[x]);\n    }\n\n\
    \    bool merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return false;\n        if (parent[x] > parent[y]) std::swap(x,\
    \ y);\n        parent[x] += parent[y];\n        parent[y] = x;\n        cnt -=\
    \ 1;\n        return true;\n    }\n\n    int same(int x, int y) { return root(x)\
    \ == root(y); }\n\n    int size(int x) { return -parent[root(x)]; }\n\n    int\
    \ count() { return cnt; }\n};\n#line 4 \"src/graph/minimum-spanning-tree/kruskal.hpp\"\
    \n\ntemplate <typename T>\nT kruskal(int n, std::vector<Edge<T>> &edges) {\n \
    \   // edges\u306F\u7834\u58CA\u7684\u306B\u30BD\u30FC\u30C8\u3055\u308C\u308B\
    \n    std::sort(edges.begin(), edges.end(), [](const Edge<T> &a, const Edge<T>\
    \ &b) { return a.cost < b.cost; });\n\n    UnionFind uf(n);\n    T total_cost\
    \ = 0;\n    for (const auto& e : edges) {\n        if (not uf.same(e.from, e.to))\
    \ {\n            uf.merge(e.from, e.to);\n            total_cost += e.cost;\n\
    \        }\n    }\n    return total_cost;\n}\n\ntemplate <typename T>\nstd::vector<Edge<T>>\
    \ kruskal_edges(int n, std::vector<Edge<T>> &edges) {\n    // edges\u306F\u7834\
    \u58CA\u7684\u306B\u30BD\u30FC\u30C8\u3055\u308C\u308B\n    std::sort(edges.begin(),\
    \ edges.end(), [](const Edge<T> &a, const Edge<T> &b) { return a.cost < b.cost;\
    \ });\n\n    std::vector<Edge<T>> result;\n    UnionFind uf(n);\n    for (const\
    \ auto& e : edges) {\n        if (not uf.same(e.from, e.to)) {\n            uf.merge(e.from,\
    \ e.to);\n            result.emplace_back(e);\n        }\n    }\n    return result;\n\
    }\n#line 5 \"tests/aoj/GRL_2_A.test.cpp\"\n\nint main() {\n    int n, m;\n   \
    \ std::cin >> n >> m;\n    std::vector<Edge<long long>> edges;\n    for (int i\
    \ = 0; i < m; i++) {\n        int u, v;\n        long long cost;\n        std::cin\
    \ >> u >> v >> cost;\n        edges.emplace_back(u, v, cost, i);\n    }\n    auto\
    \ ans = kruskal(n, edges);\n\n    auto ans_edges = kruskal_edges(n, edges);\n\
    \    long long ans2 = 0;\n    for (auto e : ans_edges) { ans2 += e.cost; }\n\n\
    \    assert(ans == ans2);\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"../../src/template/template.hpp\"\n#include \"../../src/graph/minimum-spanning-tree/kruskal.hpp\"\
    \n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<Edge<long\
    \ long>> edges;\n    for (int i = 0; i < m; i++) {\n        int u, v;\n      \
    \  long long cost;\n        std::cin >> u >> v >> cost;\n        edges.emplace_back(u,\
    \ v, cost, i);\n    }\n    auto ans = kruskal(n, edges);\n\n    auto ans_edges\
    \ = kruskal_edges(n, edges);\n    long long ans2 = 0;\n    for (auto e : ans_edges)\
    \ { ans2 += e.cost; }\n\n    assert(ans == ans2);\n\n    std::cout << ans << std::endl;\n\
    }\n"
  dependsOn:
  - src/template/template.hpp
  - src/graph/minimum-spanning-tree/kruskal.hpp
  - src/graph/graph-template.hpp
  - src/data-structure/union-find/union-find.hpp
  isVerificationFile: true
  path: tests/aoj/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2023-12-30 14:53:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/GRL_2_A.test.cpp
- /verify/tests/aoj/GRL_2_A.test.cpp.html
title: tests/aoj/GRL_2_A.test.cpp
---
