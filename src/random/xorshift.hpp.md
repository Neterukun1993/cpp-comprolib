---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/random/xorshift.hpp\"\n#include <cstdint>\n\n\nuint64_t\
    \ rand64() {\n    static uint64_t x = 88172645463325252ULL;\n    x = x ^ (x <<\
    \ 7);\n    return x = x ^ (x >> 9);\n}\n\ndouble rand_p() {\n    return rand64()\
    \ * (1.0 / UINT64_MAX);\n}\n"
  code: "#include <cstdint>\n\n\nuint64_t rand64() {\n    static uint64_t x = 88172645463325252ULL;\n\
    \    x = x ^ (x << 7);\n    return x = x ^ (x >> 9);\n}\n\ndouble rand_p() {\n\
    \    return rand64() * (1.0 / UINT64_MAX);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/random/xorshift.hpp
  requiredBy: []
  timestamp: '2022-04-05 22:25:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/random/xorshift.hpp
layout: document
redirect_from:
- /library/src/random/xorshift.hpp
- /library/src/random/xorshift.hpp.html
title: src/random/xorshift.hpp
---
