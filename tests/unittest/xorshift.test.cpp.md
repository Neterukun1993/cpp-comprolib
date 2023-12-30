---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/xorshift.hpp
    title: src/random/xorshift.hpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"tests/unittest/xorshift.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#line 1 \"src/template/template.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <cstring>\n#include <deque>\n#include <iostream>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\n#define REP(i, n) for (int i = 0; i < (int)(n); ++ (i))\n#define\
    \ REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#line 2 \"src/random/xorshift.hpp\"\
    \n\nuint64_t rand64() {\n    static uint64_t x = 88172645463325252ULL;\n    x\
    \ = x ^ (x << 7);\n    return x = x ^ (x >> 9);\n}\n\ndouble rand_p() { return\
    \ rand64() * (1.0 / UINT64_MAX); }\n#line 5 \"tests/unittest/xorshift.test.cpp\"\
    \n\nint main() {\n    std::vector<uint64_t> sample = { 11373782495151020392, 8505512047393832734,\
    \ 8278699350803616934, 220332960558298757, 9524873121654605887 };\n    for (auto\
    \ expected : sample) {\n        assert(expected == rand64());\n    }\n\n    std::cout\
    \ << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../src/template/template.hpp\"\n#include \"../../src/random/xorshift.hpp\"\
    \n\nint main() {\n    std::vector<uint64_t> sample = { 11373782495151020392, 8505512047393832734,\
    \ 8278699350803616934, 220332960558298757, 9524873121654605887 };\n    for (auto\
    \ expected : sample) {\n        assert(expected == rand64());\n    }\n\n    std::cout\
    \ << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/random/xorshift.hpp
  isVerificationFile: true
  path: tests/unittest/xorshift.test.cpp
  requiredBy: []
  timestamp: '2023-12-30 14:52:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/unittest/xorshift.test.cpp
layout: document
redirect_from:
- /verify/tests/unittest/xorshift.test.cpp
- /verify/tests/unittest/xorshift.test.cpp.html
title: tests/unittest/xorshift.test.cpp
---
