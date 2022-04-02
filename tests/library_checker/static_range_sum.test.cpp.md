---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/cumulative-sum.hpp
    title: src/data-structure/cumulative-sum.hpp
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
  bundledCode: "#line 1 \"tests/library_checker/static_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <iostream>\n\
    #include <vector>\n#line 2 \"src/data-structure/cumulative-sum.hpp\"\n\n\ntemplate\
    \ <typename T>\nstruct CumulativeSum {\n    std::vector<T> cumsum;\n\n    CumulativeSum(int\
    \ n) : cumsum(n + 1, 0) {}\n\n    void add(int i, T value) { cumsum[i + 1] +=\
    \ value; }\n\n    void build() {\n        for (int i = 0; i < (int)cumsum.size()\
    \ - 1; i++) {\n            cumsum[i + 1] += cumsum[i];\n        }\n    }\n\n \
    \   T sum(int l, int r) {\n        // sum of values in range [l, r)\n        return\
    \ cumsum[r] - cumsum[l];\n    }\n};\n#line 6 \"tests/library_checker/static_range_sum.test.cpp\"\
    \n\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long\
    \ long> a(n);\n    for (auto& val : a) std::cin >> val;\n\n    CumulativeSum<long\
    \ long> cumsum(n);\n    for (int i = 0; i < n; i++) {\n        cumsum.add(i, a[i]);\n\
    \    }\n    cumsum.build();\n\n    for (int i = 0; i < q; i++) {\n        int\
    \ l, r;\n        std::cin >> l >> r;\n        std::cout << cumsum.sum(l, r) <<\
    \ std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"../../src/data-structure/cumulative-sum.hpp\"\
    \n\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long\
    \ long> a(n);\n    for (auto& val : a) std::cin >> val;\n\n    CumulativeSum<long\
    \ long> cumsum(n);\n    for (int i = 0; i < n; i++) {\n        cumsum.add(i, a[i]);\n\
    \    }\n    cumsum.build();\n\n    for (int i = 0; i < q; i++) {\n        int\
    \ l, r;\n        std::cin >> l >> r;\n        std::cout << cumsum.sum(l, r) <<\
    \ std::endl;\n    }\n}\n"
  dependsOn:
  - src/data-structure/cumulative-sum.hpp
  isVerificationFile: true
  path: tests/library_checker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-04-03 02:10:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/library_checker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/tests/library_checker/static_range_sum.test.cpp
- /verify/tests/library_checker/static_range_sum.test.cpp.html
title: tests/library_checker/static_range_sum.test.cpp
---
