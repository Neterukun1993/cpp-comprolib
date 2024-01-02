---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: src/graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_3_A.test.cpp
    title: tests/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_3_B.test.cpp
    title: tests/aoj/GRL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/graph-template.hpp\"\n\ntemplate <typename T>\n\
    struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\n    Edge(int from,\
    \ int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}\n};\n\n\
    template <typename T>\nstruct Graph {\n    bool is_directed;\n    int N, M;\n\
    \    std::vector<std::vector<Edge<T>>> adjacencies;\n\n    Graph(bool is_directed\
    \ = true) : is_directed(is_directed), N(0), M(0), adjacencies(0) {}\n\n    Graph(int\
    \ N, bool is_directed = true) : is_directed(is_directed), N(N), M(0), adjacencies(N)\
    \ {}\n\n    inline const std::vector<Edge<T>> &operator[] (int k ) const {return\
    \ adjacencies[k]; }\n\n    void init(int N_) {\n        N = N_;\n        M = 0;\n\
    \        adjacencies.clear();\n        adjacencies.resize(N);\n    }\n\n    int\
    \ size() const { return N; }\n\n    void add_edge(int from, int to, T cost, int\
    \ id) {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to\
    \ < N);\n        auto e = Edge<T>(from, to, cost, id);\n\n        adjacencies[from].emplace_back(e);\n\
    \        if (!is_directed) {\n            auto e2 = Edge<T>(to, from, cost, id);\n\
    \            adjacencies[to].emplace_back(e2);\n        }\n\n        M++;\n  \
    \  }\n};\n#line 3 \"src/graph/misc/low-link.hpp\"\n\ntemplate <typename T>\nstruct\
    \ LowLink {\n    const Graph<T> &g;\n    std::vector<int> used, ord, low;\n  \
    \  std::vector<int> articulation_points;\n    std::vector<int> bridges;\n\n  \
    \  LowLink(const Graph<T> &g) : g(g) {}\n\n    void build() {\n        used.assign(g.size(),\
    \ 0);\n        ord.assign(g.size(), 0);\n        low.assign(g.size(), 0);\n\n\
    \        int k = 0;\n        for (int i = 0; i < (int)g.size(); i++) {\n     \
    \       if (!used[i]) k = dfs(i, k, -1);\n        }\n        // std::sort(aps.begin(),\
    \ aps.end());\n        // std::sort(briges.begin(), bridges.end(), [](const Edge\
    \ &a, const Edge &b) {\n        //     return a.id < b.id;\n        // }\n   \
    \ }\n\n    private:\n        int dfs(int id, int k, int par) {\n            used[id]\
    \ = true;\n            ord[id] = k++;\n            low[id] = ord[id];\n      \
    \      bool is_articulation = false;\n            int count = 0;\n\n         \
    \   for (const auto &e : g[id]) {\n                if (!used[e.to]) {\n      \
    \              count++;\n                    k = dfs(e.to, k, id);\n         \
    \           low[id] = std::min(low[id], low[e.to]);\n                    is_articulation\
    \ |= (par != -1 && ord[id] <= low[e.to]); \n                    if (ord[id] <\
    \ low[e.to]) bridges.push_back(e.id);\n                } else if (e.to != par)\
    \ {\n                    low[id] = std::min(low[id], ord[e.to]);\n           \
    \     }\n            }\n            if (par == -1 && count > 1) is_articulation\
    \ = true;\n            if (is_articulation) articulation_points.push_back(id);\n\
    \            return k;\n        }\n};\n"
  code: "#pragma once\n#include \"../graph-template.hpp\"\n\ntemplate <typename T>\n\
    struct LowLink {\n    const Graph<T> &g;\n    std::vector<int> used, ord, low;\n\
    \    std::vector<int> articulation_points;\n    std::vector<int> bridges;\n\n\
    \    LowLink(const Graph<T> &g) : g(g) {}\n\n    void build() {\n        used.assign(g.size(),\
    \ 0);\n        ord.assign(g.size(), 0);\n        low.assign(g.size(), 0);\n\n\
    \        int k = 0;\n        for (int i = 0; i < (int)g.size(); i++) {\n     \
    \       if (!used[i]) k = dfs(i, k, -1);\n        }\n        // std::sort(aps.begin(),\
    \ aps.end());\n        // std::sort(briges.begin(), bridges.end(), [](const Edge\
    \ &a, const Edge &b) {\n        //     return a.id < b.id;\n        // }\n   \
    \ }\n\n    private:\n        int dfs(int id, int k, int par) {\n            used[id]\
    \ = true;\n            ord[id] = k++;\n            low[id] = ord[id];\n      \
    \      bool is_articulation = false;\n            int count = 0;\n\n         \
    \   for (const auto &e : g[id]) {\n                if (!used[e.to]) {\n      \
    \              count++;\n                    k = dfs(e.to, k, id);\n         \
    \           low[id] = std::min(low[id], low[e.to]);\n                    is_articulation\
    \ |= (par != -1 && ord[id] <= low[e.to]); \n                    if (ord[id] <\
    \ low[e.to]) bridges.push_back(e.id);\n                } else if (e.to != par)\
    \ {\n                    low[id] = std::min(low[id], ord[e.to]);\n           \
    \     }\n            }\n            if (par == -1 && count > 1) is_articulation\
    \ = true;\n            if (is_articulation) articulation_points.push_back(id);\n\
    \            return k;\n        }\n};\n"
  dependsOn:
  - src/graph/graph-template.hpp
  isVerificationFile: false
  path: src/graph/misc/low-link.hpp
  requiredBy: []
  timestamp: '2023-12-31 22:12:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/GRL_3_A.test.cpp
  - tests/aoj/GRL_3_B.test.cpp
documentation_of: src/graph/misc/low-link.hpp
layout: document
redirect_from:
- /library/src/graph/misc/low-link.hpp
- /library/src/graph/misc/low-link.hpp.html
title: src/graph/misc/low-link.hpp
---
