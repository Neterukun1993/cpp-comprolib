#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0098"

#include <iostream>
#include <vector>
#include <algorithm>
#include "../../src/data-structure/cumulative-sum-2d.hpp"


int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (auto& inner : a) {
        for (auto& val : inner) std::cin >> val;
    }

    CumulativeSum2D<int> cumsum((int)a.size(), (int)a[0].size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cumsum.add(i, j, a[i][j]);
        }
    }
    cumsum.build();

    int ans = -1'000'000'000;
    for (int hl = 0; hl < n; hl++) {
        for (int hr = hl + 1; hr < n + 1; hr++) {
            for (int wl = 0; wl < n; wl++) {
                for (int wr = wl + 1; wr < n + 1; wr++) {
                    ans = std::max(cumsum.sum(hl, hr, wl, wr), ans);
                }
            }
        }
    }
    std::cout << ans << std::endl;
}
