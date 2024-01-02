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
  bundledCode: "#line 1 \"src/misc/timer.hpp\"\n#include <chrono>\nusing namespace\
    \ std::chrono;\n\n\nstruct Timer {\n    system_clock::time_point start;\n\n  \
    \  Timer() { reset(); }\n\n    void reset() { start = system_clock::now(); }\n\
    \n    double sec_elapsed() {\n        return duration_cast<milliseconds>(system_clock::now()\
    \ - start).count() / 1000.0;\n    }\n};\n"
  code: "#include <chrono>\nusing namespace std::chrono;\n\n\nstruct Timer {\n   \
    \ system_clock::time_point start;\n\n    Timer() { reset(); }\n\n    void reset()\
    \ { start = system_clock::now(); }\n\n    double sec_elapsed() {\n        return\
    \ duration_cast<milliseconds>(system_clock::now() - start).count() / 1000.0;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/timer.hpp
  requiredBy: []
  timestamp: '2023-12-30 16:36:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/timer.hpp
layout: document
redirect_from:
- /library/src/misc/timer.hpp
- /library/src/misc/timer.hpp.html
title: src/misc/timer.hpp
---
