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
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"tests/library-checker/unionfind-with-undo.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#line 1\
    \ \"src/template/template.hpp\"\n#include <algorithm>\n#include <array>\n#include\
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
    \     undo();\n        }\n    }\n};\n#line 5 \"tests/library-checker/unionfind-with-undo.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<std::vector<std::vector<int>>>\
    \ judges(q + 1);\n    std::vector<std::vector<std::vector<int>>> merges(q + 1);\n\
    \n    REP(i, q) {\n        int flag, k, u, v;\n        std::cin >> flag >> k >>\
    \ u >> v;\n        if (flag == 0) {\n            merges[k + 1].emplace_back(std::vector<int>({\
    \ i, u, v }));\n        }\n        if (flag == 1) {\n            judges[k + 1].emplace_back(std::vector<int>({\
    \ i, u, v }));\n        }\n    }\n\n    UnionFindWithUndo uf(n);\n    std::vector<int>\
    \ answer(q, -1);\n\n    auto dfs = [&](auto dfs, int k) -> void {\n        for\
    \ (std::vector<int> judge : judges[k + 1]) {\n            // \u30B0\u30E9\u30D5\
    \ Gk \u306B\u304A\u3051\u308B\u9023\u7D50\u5224\u5B9A\u3092\u51E6\u7406\u3059\u308B\
    \n            int i = judge[0];\n            int u = judge[1];\n            int\
    \ v = judge[2];\n            answer[i] = uf.same(u, v);\n        }\n        for\
    \ (auto merge : merges[k + 1]) {\n            // \u30B0\u30E9\u30D5 Gk \u306B\u304A\
    \u3051\u308B\u8FBA\u306E\u8FFD\u52A0\u3092\u51E6\u7406\u3059\u308B\n         \
    \   int i = merge[0];\n            int u = merge[1];\n            int v = merge[2];\n\
    \            uf.merge(u, v);\n            dfs(dfs, i);\n            uf.undo();\n\
    \        }\n    };\n\n    uf.snapshot();\n    dfs(dfs, -1);\n\n    REP(i, q) {\n\
    \        if (answer[i] != -1) std::cout << answer[i] << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../../src/template/template.hpp\"\n#include \"../../src/data-structure/union-find/union-find-with-undo.hpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<std::vector<std::vector<int>>>\
    \ judges(q + 1);\n    std::vector<std::vector<std::vector<int>>> merges(q + 1);\n\
    \n    REP(i, q) {\n        int flag, k, u, v;\n        std::cin >> flag >> k >>\
    \ u >> v;\n        if (flag == 0) {\n            merges[k + 1].emplace_back(std::vector<int>({\
    \ i, u, v }));\n        }\n        if (flag == 1) {\n            judges[k + 1].emplace_back(std::vector<int>({\
    \ i, u, v }));\n        }\n    }\n\n    UnionFindWithUndo uf(n);\n    std::vector<int>\
    \ answer(q, -1);\n\n    auto dfs = [&](auto dfs, int k) -> void {\n        for\
    \ (std::vector<int> judge : judges[k + 1]) {\n            // \u30B0\u30E9\u30D5\
    \ Gk \u306B\u304A\u3051\u308B\u9023\u7D50\u5224\u5B9A\u3092\u51E6\u7406\u3059\u308B\
    \n            int i = judge[0];\n            int u = judge[1];\n            int\
    \ v = judge[2];\n            answer[i] = uf.same(u, v);\n        }\n        for\
    \ (auto merge : merges[k + 1]) {\n            // \u30B0\u30E9\u30D5 Gk \u306B\u304A\
    \u3051\u308B\u8FBA\u306E\u8FFD\u52A0\u3092\u51E6\u7406\u3059\u308B\n         \
    \   int i = merge[0];\n            int u = merge[1];\n            int v = merge[2];\n\
    \            uf.merge(u, v);\n            dfs(dfs, i);\n            uf.undo();\n\
    \        }\n    };\n\n    uf.snapshot();\n    dfs(dfs, -1);\n\n    REP(i, q) {\n\
    \        if (answer[i] != -1) std::cout << answer[i] << std::endl;\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data-structure/union-find/union-find-with-undo.hpp
  isVerificationFile: true
  path: tests/library-checker/unionfind-with-undo.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:53:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/library-checker/unionfind-with-undo.test.cpp
layout: document
redirect_from:
- /verify/tests/library-checker/unionfind-with-undo.test.cpp
- /verify/tests/library-checker/unionfind-with-undo.test.cpp.html
title: tests/library-checker/unionfind-with-undo.test.cpp
---
