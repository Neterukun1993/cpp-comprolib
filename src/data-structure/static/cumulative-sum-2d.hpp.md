---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/0098.test.cpp
    title: tests/aoj/0098.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/static/cumulative-sum-2d.hpp\"\n\ntemplate\
    \ <typename T>\nstruct CumulativeSum2D {\n    int h, w;\n    std::vector<T> cumsum;\n\
    \n    CumulativeSum2D(int h, int w) : h(h), w(w), cumsum((h + 1) * (w + 1), 0)\
    \ {}\n\n    void add(int i, int j, T value) { cumsum[(i + 1) * (w + 1) + j + 1]\
    \ += value; }\n\n    void build() {\n        for (int i = 0; i < h; i++) {\n \
    \           for (int j = 0; j < w; j++) {\n                cumsum[(i + 1) * (w\
    \ + 1) + j + 1] += cumsum[(i + 1) * (w + 1) + j] + cumsum[i * (w + 1) + j + 1]\
    \ - cumsum[i * (w + 1) + j];\n            }\n        }\n    }\n\n    T sum(int\
    \ hl, int hr, int wl, int wr) {\n        // sum of values in range [hl, hr) *\
    \ [wl, wr)\n        return cumsum[hr * (w + 1) + wr] + cumsum[hl * (w + 1) + wl]\
    \ - cumsum[hr * (w + 1) + wl] - cumsum[hl * (w + 1) + wr];\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct CumulativeSum2D {\n    int\
    \ h, w;\n    std::vector<T> cumsum;\n\n    CumulativeSum2D(int h, int w) : h(h),\
    \ w(w), cumsum((h + 1) * (w + 1), 0) {}\n\n    void add(int i, int j, T value)\
    \ { cumsum[(i + 1) * (w + 1) + j + 1] += value; }\n\n    void build() {\n    \
    \    for (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n\
    \                cumsum[(i + 1) * (w + 1) + j + 1] += cumsum[(i + 1) * (w + 1)\
    \ + j] + cumsum[i * (w + 1) + j + 1] - cumsum[i * (w + 1) + j];\n            }\n\
    \        }\n    }\n\n    T sum(int hl, int hr, int wl, int wr) {\n        // sum\
    \ of values in range [hl, hr) * [wl, wr)\n        return cumsum[hr * (w + 1) +\
    \ wr] + cumsum[hl * (w + 1) + wl] - cumsum[hr * (w + 1) + wl] - cumsum[hl * (w\
    \ + 1) + wr];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/static/cumulative-sum-2d.hpp
  requiredBy: []
  timestamp: '2024-01-03 22:05:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/0098.test.cpp
documentation_of: src/data-structure/static/cumulative-sum-2d.hpp
layout: document
redirect_from:
- /library/src/data-structure/static/cumulative-sum-2d.hpp
- /library/src/data-structure/static/cumulative-sum-2d.hpp.html
title: src/data-structure/static/cumulative-sum-2d.hpp
---
