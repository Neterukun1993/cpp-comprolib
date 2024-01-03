#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../../src/template/template.hpp"
#include "../../src/data-structure/binary-indexed-tree/range-add-point-get.hpp"

RangeAddPointGet<int> bit(100010);

int main() {
    int n, q;
    std::cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int flag;
        std::cin >> flag;

        if (flag == 0) {
            int s, t, x;
            std::cin >> s >> t >> x;
            bit.add(s - 1, t, x);
        } else {
            int i;
            std::cin >> i;
            std::cout << bit.get(i - 1) << std::endl;
        }
    }
}