---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/binary-indexed-tree.hpp
    title: src/data-structure/binary-indexed-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"tests/library_checker/point_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"src/data-structure/binary-indexed-tree.hpp\"\
    \n\n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n    int size;\n    std::vector<T>\
    \ bit;\n\n    BinaryIndexedTree(int n) : size(n + 1), bit(size, 0) {}\n\n    void\
    \ add(int i, T x) {\n        for (int idx = i + 1; idx <= size; idx += (idx &\
    \ -idx)) {\n            bit[idx] += x;\n        }\n    }\n\n    T sum(int r) {\n\
    \        T res = 0;\n        for (int idx = r; idx > 0; idx -= (idx & -idx)) {\n\
    \            res += bit[idx];\n        }\n        return res;\n    }\n\n    T\
    \ sum(int l, int r) { return sum(r) - sum(l); }\n};\n#line 6 \"tests/library_checker/point_add_range_sum.test.cpp\"\
    \n\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long\
    \ long> a(n);\n    for (auto& val : a) std::cin >> val;\n\n    BinaryIndexedTree<long\
    \ long> bit(n);\n    for (int i = 0; i < n; i++) {\n        bit.add(i, a[i]);\n\
    \    }\n\n    for (int i = 0; i < q; i++) {\n        int flag, l, r;\n       \
    \ std::cin >> flag >> l >> r;\n        if (flag) {\n            std::cout << bit.sum(l,\
    \ r) << std::endl;\n        } else {\n            bit.add(l, r);\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n#include \"../../src/data-structure/binary-indexed-tree.hpp\"\
    \n\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long\
    \ long> a(n);\n    for (auto& val : a) std::cin >> val;\n\n    BinaryIndexedTree<long\
    \ long> bit(n);\n    for (int i = 0; i < n; i++) {\n        bit.add(i, a[i]);\n\
    \    }\n\n    for (int i = 0; i < q; i++) {\n        int flag, l, r;\n       \
    \ std::cin >> flag >> l >> r;\n        if (flag) {\n            std::cout << bit.sum(l,\
    \ r) << std::endl;\n        } else {\n            bit.add(l, r);\n        }\n\
    \    }\n}\n"
  dependsOn:
  - src/data-structure/binary-indexed-tree.hpp
  isVerificationFile: true
  path: tests/library_checker/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-04-03 01:54:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/library_checker/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/tests/library_checker/point_add_range_sum.test.cpp
- /verify/tests/library_checker/point_add_range_sum.test.cpp.html
title: tests/library_checker/point_add_range_sum.test.cpp
---
