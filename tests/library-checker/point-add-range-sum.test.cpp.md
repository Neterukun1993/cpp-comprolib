---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/binary-indexed-tree/point-add-range-sum.hpp
    title: src/data-structure/binary-indexed-tree/point-add-range-sum.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"tests/library-checker/point-add-range-sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 1 \"\
    src/template/template.hpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <cstring>\n#include <deque>\n#include <iostream>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\n#define REP(i, n) for (int i = 0; i < (int)(n); ++ (i))\n#define\
    \ REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#line 2 \"src/data-structure/binary-indexed-tree/point-add-range-sum.hpp\"\
    \n\ntemplate <typename T>\nstruct PointAddRangeSum {\n    int size;\n    std::vector<T>\
    \ bit;\n\n    PointAddRangeSum(int n) : size(n + 1), bit(size, 0) {}\n\n    void\
    \ clear() { std::fill(bit.begin(), bit.end(), 0); }\n\n    void add(int i, T x)\
    \ {\n        for (int idx = i + 1; idx <= size; idx += (idx & -idx)) {\n     \
    \       bit[idx] += x;\n        }\n    }\n\n    T sum(int r) {\n        T res\
    \ = 0;\n        for (int idx = r; idx > 0; idx -= (idx & -idx)) {\n          \
    \  res += bit[idx];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) { return sum(r) - sum(l); }\n};\n#line 5 \"tests/library-checker/point-add-range-sum.test.cpp\"\
    \n\nPointAddRangeSum<long long> bit(500010);\n\nint main() {\n    int n, q;\n\
    \    std::cin >> n >> q;\n    std::vector<long long> a(n);\n    for (auto& val\
    \ : a) std::cin >> val;\n\n    for (int i = 0; i < n; i++) {\n        bit.add(i,\
    \ a[i]);\n    }\n\n    for (int i = 0; i < q; i++) {\n        int flag, l, r;\n\
    \        std::cin >> flag >> l >> r;\n        if (flag) {\n            std::cout\
    \ << bit.sum(l, r) << std::endl;\n        } else {\n            bit.add(l, r);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../src/template/template.hpp\"\n#include \"../../src/data-structure/binary-indexed-tree/point-add-range-sum.hpp\"\
    \n\nPointAddRangeSum<long long> bit(500010);\n\nint main() {\n    int n, q;\n\
    \    std::cin >> n >> q;\n    std::vector<long long> a(n);\n    for (auto& val\
    \ : a) std::cin >> val;\n\n    for (int i = 0; i < n; i++) {\n        bit.add(i,\
    \ a[i]);\n    }\n\n    for (int i = 0; i < q; i++) {\n        int flag, l, r;\n\
    \        std::cin >> flag >> l >> r;\n        if (flag) {\n            std::cout\
    \ << bit.sum(l, r) << std::endl;\n        } else {\n            bit.add(l, r);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/data-structure/binary-indexed-tree/point-add-range-sum.hpp
  isVerificationFile: true
  path: tests/library-checker/point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 22:46:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/library-checker/point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/tests/library-checker/point-add-range-sum.test.cpp
- /verify/tests/library-checker/point-add-range-sum.test.cpp.html
title: tests/library-checker/point-add-range-sum.test.cpp
---
