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
  bundledCode: "#line 1 \"src/data-structure/cumulative-sum-2d.hpp\"\n#include <vector>\n\
    \n\ntemplate <typename T>\nstruct CumulativeSum2D {\n    int h, w;\n    std::vector<std::vector<T>>\
    \ cumsum;\n\n    CumulativeSum2D(int h_, int w_)\n        : h(h_), w(w_), cumsum(h_\
    \ + 1, std::vector<T>(w_ + 1, 0)) {}\n\n    void add(int i, int j, T value) {\
    \ cumsum[i + 1][j + 1] += value; }\n\n    void build() {\n        for (int i =\
    \ 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n              \
    \  cumsum[i + 1][j + 1] += cumsum[i + 1][j] + cumsum[i][j + 1] - cumsum[i][j];\n\
    \            }\n        }\n    }\n\n    T sum(int hl, int hr, int wl, int wr)\
    \ {\n        // sum of values in range [hl, hr) * [wl, wr)\n        return cumsum[hr][wr]\
    \ + cumsum[hl][wl] - cumsum[hr][wl] - cumsum[hl][wr];\n    }\n};\n"
  code: "#include <vector>\n\n\ntemplate <typename T>\nstruct CumulativeSum2D {\n\
    \    int h, w;\n    std::vector<std::vector<T>> cumsum;\n\n    CumulativeSum2D(int\
    \ h_, int w_)\n        : h(h_), w(w_), cumsum(h_ + 1, std::vector<T>(w_ + 1, 0))\
    \ {}\n\n    void add(int i, int j, T value) { cumsum[i + 1][j + 1] += value; }\n\
    \n    void build() {\n        for (int i = 0; i < h; i++) {\n            for (int\
    \ j = 0; j < w; j++) {\n                cumsum[i + 1][j + 1] += cumsum[i + 1][j]\
    \ + cumsum[i][j + 1] - cumsum[i][j];\n            }\n        }\n    }\n\n    T\
    \ sum(int hl, int hr, int wl, int wr) {\n        // sum of values in range [hl,\
    \ hr) * [wl, wr)\n        return cumsum[hr][wr] + cumsum[hl][wl] - cumsum[hr][wl]\
    \ - cumsum[hl][wr];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/cumulative-sum-2d.hpp
  requiredBy: []
  timestamp: '2022-04-03 01:44:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/0098.test.cpp
documentation_of: src/data-structure/cumulative-sum-2d.hpp
layout: document
redirect_from:
- /library/src/data-structure/cumulative-sum-2d.hpp
- /library/src/data-structure/cumulative-sum-2d.hpp.html
title: src/data-structure/cumulative-sum-2d.hpp
---
