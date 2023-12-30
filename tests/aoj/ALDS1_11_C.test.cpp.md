---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: src/graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest-path/bfs.hpp
    title: src/graph/shortest-path/bfs.hpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"tests/aoj/ALDS1_11_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
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
    \        }\n\n        M++;\n    }\n};\n#line 3 \"src/graph/shortest-path/bfs.hpp\"\
    \n\ntemplate <typename T>\nvoid bfs(const Graph<T> &g, const int start, std::vector<int>\
    \ &distance) {\n    assert(g.size() == (int)distance.size());\n\n    std::fill(distance.begin(),\
    \ distance.end(), -1);\n    distance[start] = 0;\n\n    static std::queue<int>\
    \ que;\n    que.push(start);\n\n    while (not que.empty()) {\n        const int\
    \ v = que.front();\n        que.pop();\n\n        for (const auto& e: g[v]) {\n\
    \            if (distance[e.to] != -1) continue;\n            distance[e.to] =\
    \ distance[v] + 1;\n            que.push(e.to);\n        }\n    }\n}\n#line 5\
    \ \"tests/aoj/ALDS1_11_C.test.cpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n\n    Graph<int> g(n);\n    for (int i = 0; i < n; i++) {\n        int\
    \ v, k, nxt_v;\n        std::cin >> v >> k;\n        v -= 1;\n        for (int\
    \ j = 0; j < k; j++) {\n            std::cin >> nxt_v;\n            nxt_v -= 1;\n\
    \            g.add_edge(v, nxt_v, 1, -1);\n        }\n    }\n\n    std::vector<int>\
    \ distance(n);\n    bfs(g, 0, distance);\n    for (int v = 0; v < n; v++) {\n\
    \        std::cout << v + 1 << \" \" << distance[v] << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include \"../../src/template/template.hpp\"\n#include \"../../src/graph/shortest-path/bfs.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    Graph<int> g(n);\n   \
    \ for (int i = 0; i < n; i++) {\n        int v, k, nxt_v;\n        std::cin >>\
    \ v >> k;\n        v -= 1;\n        for (int j = 0; j < k; j++) {\n          \
    \  std::cin >> nxt_v;\n            nxt_v -= 1;\n            g.add_edge(v, nxt_v,\
    \ 1, -1);\n        }\n    }\n\n    std::vector<int> distance(n);\n    bfs(g, 0,\
    \ distance);\n    for (int v = 0; v < n; v++) {\n        std::cout << v + 1 <<\
    \ \" \" << distance[v] << std::endl;\n    }\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/graph/shortest-path/bfs.hpp
  - src/graph/graph-template.hpp
  isVerificationFile: true
  path: tests/aoj/ALDS1_11_C.test.cpp
  requiredBy: []
  timestamp: '2023-12-30 14:53:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/ALDS1_11_C.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/ALDS1_11_C.test.cpp
- /verify/tests/aoj/ALDS1_11_C.test.cpp.html
title: tests/aoj/ALDS1_11_C.test.cpp
---
