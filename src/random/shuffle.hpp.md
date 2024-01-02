---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/xorshift.hpp
    title: src/random/xorshift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/unittest/shuffle.test.cpp
    title: tests/unittest/shuffle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/random/xorshift.hpp\"\n\nuint64_t rand64() {\n    static\
    \ uint64_t x = 88172645463325252ULL;\n    x = x ^ (x << 7);\n    return x = x\
    \ ^ (x >> 9);\n}\n\ndouble rand_p() { return rand64() * (1.0 / UINT64_MAX); }\n\
    #line 3 \"src/random/shuffle.hpp\"\n\ntemplate <typename T>\nvoid shuffle(std::vector<T>\
    \ &vec) {\n    for (int i = (int)vec.size(); i > 1; i--) {\n        std::swap(vec[i\
    \ - 1], vec[rand64() % i]);\n    }\n}\n\n// [l, r)\u306E\u7BC4\u56F2\u3092\u30B7\
    \u30E3\u30C3\u30D5\u30EB\ntemplate <typename T>\nvoid shuffle(std::vector<T> &vec,\
    \ const int l, const int r) {\n    assert(l <= r && 0 <= l && r <= (int)vec.size());\n\
    \    const int d = r - l;\n    for (int i = d; i > 1; i--) {\n        std::swap(vec[l\
    \ + i - 1], vec[l + rand64() % i]);\n    }\n}\n"
  code: "#pragma once\n#include \"../../src/random/xorshift.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(std::vector<T> &vec) {\n    for (int i = (int)vec.size(); i\
    \ > 1; i--) {\n        std::swap(vec[i - 1], vec[rand64() % i]);\n    }\n}\n\n\
    // [l, r)\u306E\u7BC4\u56F2\u3092\u30B7\u30E3\u30C3\u30D5\u30EB\ntemplate <typename\
    \ T>\nvoid shuffle(std::vector<T> &vec, const int l, const int r) {\n    assert(l\
    \ <= r && 0 <= l && r <= (int)vec.size());\n    const int d = r - l;\n    for\
    \ (int i = d; i > 1; i--) {\n        std::swap(vec[l + i - 1], vec[l + rand64()\
    \ % i]);\n    }\n}\n"
  dependsOn:
  - src/random/xorshift.hpp
  isVerificationFile: false
  path: src/random/shuffle.hpp
  requiredBy: []
  timestamp: '2023-12-30 18:15:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/unittest/shuffle.test.cpp
documentation_of: src/random/shuffle.hpp
layout: document
redirect_from:
- /library/src/random/shuffle.hpp
- /library/src/random/shuffle.hpp.html
title: src/random/shuffle.hpp
---
