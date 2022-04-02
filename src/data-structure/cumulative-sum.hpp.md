---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/library_checker/static_range_sum.test.cpp
    title: tests/library_checker/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/cumulative-sum.hpp\"\n#include <vector>\n\
    \n\ntemplate <typename T>\nstruct CumulativeSum {\n    std::vector<T> cumsum;\n\
    \n    CumulativeSum(int n) : cumsum(n + 1, 0) {}\n\n    void add(int i, T value)\
    \ { cumsum[i + 1] += value; }\n\n    void build() {\n        for (int i = 0; i\
    \ < (int)cumsum.size() - 1; i++) {\n            cumsum[i + 1] += cumsum[i];\n\
    \        }\n    }\n\n    T sum(int l, int r) {\n        // sum of values in range\
    \ [l, r)\n        return cumsum[r] - cumsum[l];\n    }\n};\n"
  code: "#include <vector>\n\n\ntemplate <typename T>\nstruct CumulativeSum {\n  \
    \  std::vector<T> cumsum;\n\n    CumulativeSum(int n) : cumsum(n + 1, 0) {}\n\n\
    \    void add(int i, T value) { cumsum[i + 1] += value; }\n\n    void build()\
    \ {\n        for (int i = 0; i < (int)cumsum.size() - 1; i++) {\n            cumsum[i\
    \ + 1] += cumsum[i];\n        }\n    }\n\n    T sum(int l, int r) {\n        //\
    \ sum of values in range [l, r)\n        return cumsum[r] - cumsum[l];\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/cumulative-sum.hpp
  requiredBy: []
  timestamp: '2022-04-03 02:10:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/library_checker/static_range_sum.test.cpp
documentation_of: src/data-structure/cumulative-sum.hpp
layout: document
redirect_from:
- /library/src/data-structure/cumulative-sum.hpp
- /library/src/data-structure/cumulative-sum.hpp.html
title: src/data-structure/cumulative-sum.hpp
---
