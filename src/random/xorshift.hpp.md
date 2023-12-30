---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/unittest/xorshift.test.cpp
    title: tests/unittest/xorshift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/random/xorshift.hpp\"\n\nuint64_t rand64() {\n    static\
    \ uint64_t x = 88172645463325252ULL;\n    x = x ^ (x << 7);\n    return x = x\
    \ ^ (x >> 9);\n}\n\ndouble rand_p() { return rand64() * (1.0 / UINT64_MAX); }\n"
  code: "#pragma once\n\nuint64_t rand64() {\n    static uint64_t x = 88172645463325252ULL;\n\
    \    x = x ^ (x << 7);\n    return x = x ^ (x >> 9);\n}\n\ndouble rand_p() { return\
    \ rand64() * (1.0 / UINT64_MAX); }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/random/xorshift.hpp
  requiredBy: []
  timestamp: '2023-12-30 14:52:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/unittest/xorshift.test.cpp
documentation_of: src/random/xorshift.hpp
layout: document
redirect_from:
- /library/src/random/xorshift.hpp
- /library/src/random/xorshift.hpp.html
title: src/random/xorshift.hpp
---
