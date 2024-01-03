#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../src/template/template.hpp"
#include "../../src/data-structure/static/cumulative-sum.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& val : a) std::cin >> val;

    CumulativeSum<long long> cumsum(n);
    for (int i = 0; i < n; i++) {
        cumsum.add(i, a[i]);
    }
    cumsum.build();

    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << cumsum.sum(l, r) << std::endl;
    }
}
