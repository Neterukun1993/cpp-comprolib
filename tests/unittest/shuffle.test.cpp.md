---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/shuffle.hpp
    title: src/random/shuffle.hpp
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
  bundledCode: "#line 1 \"tests/unittest/shuffle.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#line 1 \"src/template/template.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <cstring>\n#include <deque>\n#include <iostream>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\n#define REP(i, n) for (int i = 0; i < (int)(n); ++ (i))\n#define\
    \ REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#line 2 \"src/random/xorshift.hpp\"\
    \n\nuint64_t rand64() {\n    static uint64_t x = 88172645463325252ULL;\n    x\
    \ = x ^ (x << 7);\n    return x = x ^ (x >> 9);\n}\n\ndouble rand_p() { return\
    \ rand64() * (1.0 / UINT64_MAX); }\n#line 3 \"src/random/shuffle.hpp\"\n\ntemplate\
    \ <typename T>\nvoid shuffle(std::vector<T> &vec) {\n    for (int i = (int)vec.size();\
    \ i > 1; i--) {\n        std::swap(vec[i - 1], vec[rand64() % i]);\n    }\n}\n\
    \n// [l, r)\u306E\u7BC4\u56F2\u3092\u30B7\u30E3\u30C3\u30D5\u30EB\ntemplate <typename\
    \ T>\nvoid shuffle(std::vector<T> &vec, const int l, const int r) {\n    assert(l\
    \ <= r && 0 <= l && r <= (int)vec.size());\n    const int d = r - l;\n    for\
    \ (int i = d; i > 1; i--) {\n        std::swap(vec[l + i - 1], vec[l + rand64()\
    \ % i]);\n    }\n}\n#line 5 \"tests/unittest/shuffle.test.cpp\"\n\nvoid test_all_shuffle()\
    \ {\n    int vec_size = 10;\n    int shuffle_count = 1000000;\n\n    std::vector<int>\
    \ a(vec_size);\n    std::vector<std::vector<int>> counter(vec_size, std::vector<int>(vec_size,\
    \ 0));\n\n    for (int i = 0; i < vec_size; i++) { a[i] = i; }\n    for (int try_cnt\
    \ = 0; try_cnt < shuffle_count; try_cnt++) {\n        shuffle(a);\n        for\
    \ (int i = 0; i < vec_size; i++) {\n            assert(0 <= a[i] && a[i] < vec_size);\n\
    \            counter[i][a[i]] += 1;\n        }\n    }\n\n    for (int i = 0; i\
    \ < vec_size; i++) {\n        for (int j = 0; j < vec_size; j++) {\n         \
    \   assert(shuffle_count / vec_size - 1000 <= counter[i][j] && counter[i][j] <=\
    \ shuffle_count / vec_size + 1000);\n        }\n    }\n}\n\nvoid test_range_shuffle()\
    \ {\n    int vec_size = 10;\n    int l = 2;\n    int r = 7;\n    int shuffle_count\
    \ = 1000000;\n\n    std::vector<int> a(vec_size);\n    std::vector<std::vector<int>>\
    \ counter(vec_size, std::vector<int>(vec_size, 0));\n\n    for (int i = 0; i <\
    \ vec_size; i++) { a[i] = i; }\n    for (int try_cnt = 0; try_cnt < shuffle_count;\
    \ try_cnt++) {\n        shuffle(a, 2, 7);\n        for (int i = 0; i < vec_size;\
    \ i++) {\n            assert(0 <= a[i] && a[i] < vec_size);\n            counter[i][a[i]]\
    \ += 1;\n        }\n    }\n\n    for (int i = 0; i < vec_size; i++) {\n      \
    \  for (int j = 0; j < vec_size; j++) {\n            if (l <= i && i < r) {\n\
    \                if (l <= j && j < r) { assert(2 * shuffle_count / vec_size -\
    \ 1000 <= counter[i][j] && counter[i][j] <= 2 * shuffle_count / vec_size + 1000);\
    \ }\n                else { assert(counter[i][j] == 0); }\n            } else\
    \ {\n                if (i == j) { assert(counter[i][j] == shuffle_count); }\n\
    \                else { assert(counter[i][j] == 0); }\n            }   \n    \
    \    }\n    }\n}\n\nint main() {\n    test_all_shuffle();\n    test_range_shuffle();\n\
    \    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../src/template/template.hpp\"\n#include \"../../src/random/shuffle.hpp\"\
    \n\nvoid test_all_shuffle() {\n    int vec_size = 10;\n    int shuffle_count =\
    \ 1000000;\n\n    std::vector<int> a(vec_size);\n    std::vector<std::vector<int>>\
    \ counter(vec_size, std::vector<int>(vec_size, 0));\n\n    for (int i = 0; i <\
    \ vec_size; i++) { a[i] = i; }\n    for (int try_cnt = 0; try_cnt < shuffle_count;\
    \ try_cnt++) {\n        shuffle(a);\n        for (int i = 0; i < vec_size; i++)\
    \ {\n            assert(0 <= a[i] && a[i] < vec_size);\n            counter[i][a[i]]\
    \ += 1;\n        }\n    }\n\n    for (int i = 0; i < vec_size; i++) {\n      \
    \  for (int j = 0; j < vec_size; j++) {\n            assert(shuffle_count / vec_size\
    \ - 1000 <= counter[i][j] && counter[i][j] <= shuffle_count / vec_size + 1000);\n\
    \        }\n    }\n}\n\nvoid test_range_shuffle() {\n    int vec_size = 10;\n\
    \    int l = 2;\n    int r = 7;\n    int shuffle_count = 1000000;\n\n    std::vector<int>\
    \ a(vec_size);\n    std::vector<std::vector<int>> counter(vec_size, std::vector<int>(vec_size,\
    \ 0));\n\n    for (int i = 0; i < vec_size; i++) { a[i] = i; }\n    for (int try_cnt\
    \ = 0; try_cnt < shuffle_count; try_cnt++) {\n        shuffle(a, 2, 7);\n    \
    \    for (int i = 0; i < vec_size; i++) {\n            assert(0 <= a[i] && a[i]\
    \ < vec_size);\n            counter[i][a[i]] += 1;\n        }\n    }\n\n    for\
    \ (int i = 0; i < vec_size; i++) {\n        for (int j = 0; j < vec_size; j++)\
    \ {\n            if (l <= i && i < r) {\n                if (l <= j && j < r)\
    \ { assert(2 * shuffle_count / vec_size - 1000 <= counter[i][j] && counter[i][j]\
    \ <= 2 * shuffle_count / vec_size + 1000); }\n                else { assert(counter[i][j]\
    \ == 0); }\n            } else {\n                if (i == j) { assert(counter[i][j]\
    \ == shuffle_count); }\n                else { assert(counter[i][j] == 0); }\n\
    \            }   \n        }\n    }\n}\n\nint main() {\n    test_all_shuffle();\n\
    \    test_range_shuffle();\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/random/shuffle.hpp
  - src/random/xorshift.hpp
  isVerificationFile: true
  path: tests/unittest/shuffle.test.cpp
  requiredBy: []
  timestamp: '2023-12-30 18:15:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/unittest/shuffle.test.cpp
layout: document
redirect_from:
- /verify/tests/unittest/shuffle.test.cpp
- /verify/tests/unittest/shuffle.test.cpp.html
title: tests/unittest/shuffle.test.cpp
---
