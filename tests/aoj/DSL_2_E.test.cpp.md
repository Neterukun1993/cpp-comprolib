---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/binary-indexed-tree/range-add-point-get.hpp
    title: src/data-structure/binary-indexed-tree/range-add-point-get.hpp
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: src/template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"tests/aoj/DSL_2_E.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#line 1 \"src/template/template.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <cstring>\n#include <deque>\n#include <iostream>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\n#define REP(i, n) for (int i = 0; i < (int)(n); ++ (i))\n#define\
    \ REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#line 2 \"src/data-structure/binary-indexed-tree/range-add-point-get.hpp\"\
    \n\ntemplate <typename T>\nstruct RangeAddPointGet {\n    int size;\n    std::vector<T>\
    \ bit;\n\n    RangeAddPointGet(int n) : size(n + 1), bit(size, 0) {}\n\n    void\
    \ clear() { std::fill(bit.begin(), bit.end(), 0); }\n\n    void add(int r, T x)\
    \ {\n        for (int idx = r; idx > 0; idx -= (idx & -idx)) {\n            bit[idx]\
    \ += x;\n        }\n    }\n\n    void add(int l, int r, T x) {\n        add(r,\
    \ x);\n        add(l, -x);\n    }\n\n    T get(int i) {\n        T res = 0;\n\
    \        for (int idx = i + 1; idx <= size; idx += (idx & -idx)) {\n         \
    \   res += bit[idx];\n        }\n        return res;\n    }\n};\n#line 5 \"tests/aoj/DSL_2_E.test.cpp\"\
    \n\nRangeAddPointGet<int> bit(100010);\n\nint main() {\n    int n, q;\n    std::cin\
    \ >> n >> q;\n\n    for (int i = 0; i < q; i++) {\n        int flag;\n       \
    \ std::cin >> flag;\n\n        if (flag == 0) {\n            int s, t, x;\n  \
    \          std::cin >> s >> t >> x;\n            bit.add(s - 1, t, x);\n     \
    \   } else {\n            int i;\n            std::cin >> i;\n            std::cout\
    \ << bit.get(i - 1) << std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include \"../../src/template/template.hpp\"\n#include \"../../src/data-structure/binary-indexed-tree/range-add-point-get.hpp\"\
    \n\nRangeAddPointGet<int> bit(100010);\n\nint main() {\n    int n, q;\n    std::cin\
    \ >> n >> q;\n\n    for (int i = 0; i < q; i++) {\n        int flag;\n       \
    \ std::cin >> flag;\n\n        if (flag == 0) {\n            int s, t, x;\n  \
    \          std::cin >> s >> t >> x;\n            bit.add(s - 1, t, x);\n     \
    \   } else {\n            int i;\n            std::cin >> i;\n            std::cout\
    \ << bit.get(i - 1) << std::endl;\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data-structure/binary-indexed-tree/range-add-point-get.hpp
  isVerificationFile: true
  path: tests/aoj/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 22:46:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/DSL_2_E.test.cpp
- /verify/tests/aoj/DSL_2_E.test.cpp.html
title: tests/aoj/DSL_2_E.test.cpp
---
