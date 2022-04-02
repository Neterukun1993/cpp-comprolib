#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <vector>
#include "../../src/data-structure/binary-indexed-tree.hpp"


int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& val : a) std::cin >> val;

    BinaryIndexedTree<long long> bit(n);
    for (int i = 0; i < n; i++) {
        bit.add(i, a[i]);
    }

    for (int i = 0; i < q; i++) {
        int flag, l, r;
        std::cin >> flag >> l >> r;
        if (flag) {
            std::cout << bit.sum(l, r) << std::endl;
        } else {
            bit.add(l, r);
        }
    }
}
