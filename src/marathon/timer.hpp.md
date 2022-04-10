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
  bundledCode: "#line 1 \"src/marathon/timer.hpp\"\n#include <chrono>\nusing namespace\
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
  path: src/marathon/timer.hpp
  requiredBy: []
  timestamp: '2022-04-10 15:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/marathon/timer.hpp
layout: document
redirect_from:
- /library/src/marathon/timer.hpp
- /library/src/marathon/timer.hpp.html
title: src/marathon/timer.hpp
---
