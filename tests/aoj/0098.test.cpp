#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0098"

#include "../../src/template/template.hpp"
#include "../../src/data-structure/static/cumulative-sum-2d.hpp"

int main() {
    int n;
    std::cin >> n;

    CumulativeSum2D<long long> cumsum(n, n);
    REP(i, n) REP(j, n) {
        long long val;
        std::cin >> val;
        cumsum.add(i, j, val);
    }

    cumsum.build();
    long long ans = std::numeric_limits<long long>::min();
    REP(hl, n) REP3(hr, hl + 1, n + 1) REP(wl, n) REP3(wr, wl + 1, n + 1) {
        ans = std::max(ans, cumsum.sum(hl, hr, wl, wr));
    }
    std::cout << ans << std::endl;
}