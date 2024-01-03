---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/DSL_2_E.test.cpp
    title: tests/aoj/DSL_2_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/binary-indexed-tree/range-add-point-get.hpp\"\
    \n\ntemplate <typename T>\nstruct RangeAddPointGet {\n    int size;\n    std::vector<T>\
    \ bit;\n\n    RangeAddPointGet(int n) : size(n + 1), bit(size, 0) {}\n\n    void\
    \ clear() { std::fill(bit.begin(), bit.end(), 0); }\n\n    void add(int r, T x)\
    \ {\n        for (int idx = r; idx > 0; idx -= (idx & -idx)) {\n            bit[idx]\
    \ += x;\n        }\n    }\n\n    void add(int l, int r, T x) {\n        add(r,\
    \ x);\n        add(l, -x);\n    }\n\n    T get(int i) {\n        T res = 0;\n\
    \        for (int idx = i + 1; idx <= size; idx += (idx & -idx)) {\n         \
    \   res += bit[idx];\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct RangeAddPointGet {\n    int\
    \ size;\n    std::vector<T> bit;\n\n    RangeAddPointGet(int n) : size(n + 1),\
    \ bit(size, 0) {}\n\n    void clear() { std::fill(bit.begin(), bit.end(), 0);\
    \ }\n\n    void add(int r, T x) {\n        for (int idx = r; idx > 0; idx -= (idx\
    \ & -idx)) {\n            bit[idx] += x;\n        }\n    }\n\n    void add(int\
    \ l, int r, T x) {\n        add(r, x);\n        add(l, -x);\n    }\n\n    T get(int\
    \ i) {\n        T res = 0;\n        for (int idx = i + 1; idx <= size; idx +=\
    \ (idx & -idx)) {\n            res += bit[idx];\n        }\n        return res;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/binary-indexed-tree/range-add-point-get.hpp
  requiredBy: []
  timestamp: '2024-01-03 22:46:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/DSL_2_E.test.cpp
documentation_of: src/data-structure/binary-indexed-tree/range-add-point-get.hpp
layout: document
redirect_from:
- /library/src/data-structure/binary-indexed-tree/range-add-point-get.hpp
- /library/src/data-structure/binary-indexed-tree/range-add-point-get.hpp.html
title: src/data-structure/binary-indexed-tree/range-add-point-get.hpp
---
