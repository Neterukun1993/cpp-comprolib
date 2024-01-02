---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: src/graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/misc/low-link.hpp
    title: src/graph/misc/low-link.hpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"tests/aoj/GRL_3_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
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
    \        }\n\n        M++;\n    }\n};\n#line 3 \"src/graph/misc/low-link.hpp\"\
    \n\ntemplate <typename T>\nstruct LowLink {\n    const Graph<T> &g;\n    std::vector<int>\
    \ used, ord, low;\n    std::vector<int> articulation_points;\n    std::vector<int>\
    \ bridges;\n\n    LowLink(const Graph<T> &g) : g(g) {}\n\n    void build() {\n\
    \        used.assign(g.size(), 0);\n        ord.assign(g.size(), 0);\n       \
    \ low.assign(g.size(), 0);\n\n        int k = 0;\n        for (int i = 0; i <\
    \ (int)g.size(); i++) {\n            if (!used[i]) k = dfs(i, k, -1);\n      \
    \  }\n        // std::sort(aps.begin(), aps.end());\n        // std::sort(briges.begin(),\
    \ bridges.end(), [](const Edge &a, const Edge &b) {\n        //     return a.id\
    \ < b.id;\n        // }\n    }\n\n    private:\n        int dfs(int id, int k,\
    \ int par) {\n            used[id] = true;\n            ord[id] = k++;\n     \
    \       low[id] = ord[id];\n            bool is_articulation = false;\n      \
    \      int count = 0;\n\n            for (const auto &e : g[id]) {\n         \
    \       if (!used[e.to]) {\n                    count++;\n                   \
    \ k = dfs(e.to, k, id);\n                    low[id] = std::min(low[id], low[e.to]);\n\
    \                    is_articulation |= (par != -1 && ord[id] <= low[e.to]); \n\
    \                    if (ord[id] < low[e.to]) bridges.push_back(e.id);\n     \
    \           } else if (e.to != par) {\n                    low[id] = std::min(low[id],\
    \ ord[e.to]);\n                }\n            }\n            if (par == -1 &&\
    \ count > 1) is_articulation = true;\n            if (is_articulation) articulation_points.push_back(id);\n\
    \            return k;\n        }\n};\n#line 5 \"tests/aoj/GRL_3_B.test.cpp\"\n\
    \nint main() {\n    int v, e;\n    std::cin >> v >> e;\n\n    Graph<int> g(v,\
    \ false);\n    std::vector<Edge<int>> edges;\n    for (int i = 0; i < e; i++)\
    \ {\n        int s, t;\n        std::cin >> s >> t;\n        if (s > t) std::swap(s,\
    \ t);\n        g.add_edge(s, t, 1, i);\n        edges.emplace_back(s, t, 1, i);\n\
    \    }\n\n    LowLink lowlink(g);\n    lowlink.build();\n\n    auto result = lowlink.bridges;\n\
    \    std::sort(result.begin(), result.end(), [&](const int &a, const int &b) {\n\
    \        return std::make_pair(edges[a].from, edges[a].to) < std::make_pair(edges[b].from,\
    \ edges[b].to);\n    });\n    for (auto v : result) std::cout << edges[v].from\
    \ << \" \" << edges[v].to << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include \"../../src/template/template.hpp\"\n#include \"../../src/graph/misc/low-link.hpp\"\
    \n\nint main() {\n    int v, e;\n    std::cin >> v >> e;\n\n    Graph<int> g(v,\
    \ false);\n    std::vector<Edge<int>> edges;\n    for (int i = 0; i < e; i++)\
    \ {\n        int s, t;\n        std::cin >> s >> t;\n        if (s > t) std::swap(s,\
    \ t);\n        g.add_edge(s, t, 1, i);\n        edges.emplace_back(s, t, 1, i);\n\
    \    }\n\n    LowLink lowlink(g);\n    lowlink.build();\n\n    auto result = lowlink.bridges;\n\
    \    std::sort(result.begin(), result.end(), [&](const int &a, const int &b) {\n\
    \        return std::make_pair(edges[a].from, edges[a].to) < std::make_pair(edges[b].from,\
    \ edges[b].to);\n    });\n    for (auto v : result) std::cout << edges[v].from\
    \ << \" \" << edges[v].to << std::endl;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/misc/low-link.hpp
  - src/graph/graph-template.hpp
  isVerificationFile: true
  path: tests/aoj/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 22:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/GRL_3_B.test.cpp
- /verify/tests/aoj/GRL_3_B.test.cpp.html
title: tests/aoj/GRL_3_B.test.cpp
---
