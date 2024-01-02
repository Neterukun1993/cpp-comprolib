#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../src/template/template.hpp"
#include "../../src/data-structure/union-find/enumerable-union-find.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;

    EnumerableUnionFind uf(n);

    for (int i = 0; i < q; i++) {
        int flag, u, v;
        std::cin >> flag >> u >> v;
        if (flag) {
            std::cout << ((uf.same(u, v)) ? 1 : 0) << std::endl;
        } else {
            uf.merge(u, v);
        }
    }
}
