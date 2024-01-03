---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/library-checker/point-add-range-sum.test.cpp
    title: tests/library-checker/point-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/binary-indexed-tree/point-add-range-sum.hpp\"\
    \n\ntemplate <typename T>\nstruct PointAddRangeSum {\n    int size;\n    std::vector<T>\
    \ bit;\n\n    PointAddRangeSum(int n) : size(n + 1), bit(size, 0) {}\n\n    void\
    \ clear() { std::fill(bit.begin(), bit.end(), 0); }\n\n    void add(int i, T x)\
    \ {\n        for (int idx = i + 1; idx <= size; idx += (idx & -idx)) {\n     \
    \       bit[idx] += x;\n        }\n    }\n\n    T sum(int r) {\n        T res\
    \ = 0;\n        for (int idx = r; idx > 0; idx -= (idx & -idx)) {\n          \
    \  res += bit[idx];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) { return sum(r) - sum(l); }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct PointAddRangeSum {\n    int\
    \ size;\n    std::vector<T> bit;\n\n    PointAddRangeSum(int n) : size(n + 1),\
    \ bit(size, 0) {}\n\n    void clear() { std::fill(bit.begin(), bit.end(), 0);\
    \ }\n\n    void add(int i, T x) {\n        for (int idx = i + 1; idx <= size;\
    \ idx += (idx & -idx)) {\n            bit[idx] += x;\n        }\n    }\n\n   \
    \ T sum(int r) {\n        T res = 0;\n        for (int idx = r; idx > 0; idx -=\
    \ (idx & -idx)) {\n            res += bit[idx];\n        }\n        return res;\n\
    \    }\n\n    T sum(int l, int r) { return sum(r) - sum(l); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/binary-indexed-tree/point-add-range-sum.hpp
  requiredBy: []
  timestamp: '2024-01-03 22:46:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/library-checker/point-add-range-sum.test.cpp
documentation_of: src/data-structure/binary-indexed-tree/point-add-range-sum.hpp
layout: document
redirect_from:
- /library/src/data-structure/binary-indexed-tree/point-add-range-sum.hpp
- /library/src/data-structure/binary-indexed-tree/point-add-range-sum.hpp.html
title: src/data-structure/binary-indexed-tree/point-add-range-sum.hpp
---
