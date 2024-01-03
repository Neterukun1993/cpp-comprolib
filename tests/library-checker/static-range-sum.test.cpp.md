---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/static/cumulative-sum.hpp
    title: src/data-structure/static/cumulative-sum.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"tests/library-checker/static-range-sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 1 \"src/template/template.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <cstdint>\n#include <cstring>\n\
    #include <deque>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <vector>\n\n#define REP(i, n) for (int i =\
    \ 0; i < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#line 2 \"src/data-structure/static/cumulative-sum.hpp\"\n\ntemplate\
    \ <typename T>\nstruct CumulativeSum {\n    std::vector<T> cumsum;\n\n    CumulativeSum(int\
    \ n) : cumsum(n + 1, 0) {}\n\n    void add(int i, T value) { cumsum[i + 1] +=\
    \ value; }\n\n    void build() {\n        for (int i = 0; i < (int)cumsum.size()\
    \ - 1; i++) {\n            cumsum[i + 1] += cumsum[i];\n        }\n    }\n\n \
    \   T sum(int l, int r) {\n        // sum of values in range [l, r)\n        return\
    \ cumsum[r] - cumsum[l];\n    }\n};\n#line 5 \"tests/library-checker/static-range-sum.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long\
    \ long> a(n);\n    for (auto& val : a) std::cin >> val;\n\n    CumulativeSum<long\
    \ long> cumsum(n);\n    for (int i = 0; i < n; i++) {\n        cumsum.add(i, a[i]);\n\
    \    }\n    cumsum.build();\n\n    for (int i = 0; i < q; i++) {\n        int\
    \ l, r;\n        std::cin >> l >> r;\n        std::cout << cumsum.sum(l, r) <<\
    \ std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../src/template/template.hpp\"\n#include \"../../src/data-structure/static/cumulative-sum.hpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long\
    \ long> a(n);\n    for (auto& val : a) std::cin >> val;\n\n    CumulativeSum<long\
    \ long> cumsum(n);\n    for (int i = 0; i < n; i++) {\n        cumsum.add(i, a[i]);\n\
    \    }\n    cumsum.build();\n\n    for (int i = 0; i < q; i++) {\n        int\
    \ l, r;\n        std::cin >> l >> r;\n        std::cout << cumsum.sum(l, r) <<\
    \ std::endl;\n    }\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/data-structure/static/cumulative-sum.hpp
  isVerificationFile: true
  path: tests/library-checker/static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 22:05:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/library-checker/static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/tests/library-checker/static-range-sum.test.cpp
- /verify/tests/library-checker/static-range-sum.test.cpp.html
title: tests/library-checker/static-range-sum.test.cpp
---
