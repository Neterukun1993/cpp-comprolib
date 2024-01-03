---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/library-checker/static-range-sum.test.cpp
    title: tests/library-checker/static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/static/cumulative-sum.hpp\"\n\ntemplate\
    \ <typename T>\nstruct CumulativeSum {\n    std::vector<T> cumsum;\n\n    CumulativeSum(int\
    \ n) : cumsum(n + 1, 0) {}\n\n    void add(int i, T value) { cumsum[i + 1] +=\
    \ value; }\n\n    void build() {\n        for (int i = 0; i < (int)cumsum.size()\
    \ - 1; i++) {\n            cumsum[i + 1] += cumsum[i];\n        }\n    }\n\n \
    \   T sum(int l, int r) {\n        // sum of values in range [l, r)\n        return\
    \ cumsum[r] - cumsum[l];\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct CumulativeSum {\n    std::vector<T>\
    \ cumsum;\n\n    CumulativeSum(int n) : cumsum(n + 1, 0) {}\n\n    void add(int\
    \ i, T value) { cumsum[i + 1] += value; }\n\n    void build() {\n        for (int\
    \ i = 0; i < (int)cumsum.size() - 1; i++) {\n            cumsum[i + 1] += cumsum[i];\n\
    \        }\n    }\n\n    T sum(int l, int r) {\n        // sum of values in range\
    \ [l, r)\n        return cumsum[r] - cumsum[l];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/static/cumulative-sum.hpp
  requiredBy: []
  timestamp: '2024-01-03 22:05:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/library-checker/static-range-sum.test.cpp
documentation_of: src/data-structure/static/cumulative-sum.hpp
layout: document
redirect_from:
- /library/src/data-structure/static/cumulative-sum.hpp
- /library/src/data-structure/static/cumulative-sum.hpp.html
title: src/data-structure/static/cumulative-sum.hpp
---
