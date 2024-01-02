#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../src/template/template.hpp"
#include "../../src/data-structure/union-find/enumerable-union-find.hpp"

int main() {
    EnumerableUnionFind uf(6);

    // [0], [1, 2], [3, 4, 5]
    uf.merge(1, 2);
    uf.merge(3, 4);
    uf.merge(4, 5);

    std::vector<int> group;

    REP3(val, 0, 1) {
        group = uf.group(val);
        assert(group.size() == 1);
        assert(std::find(group.begin(), group.end(), val) != group.end());
    }
    REP3(val, 1, 3) {
        group = uf.group(val);
        assert(group.size() == 2);
        assert(std::find(group.begin(), group.end(), val) != group.end());
    }
    REP3(val, 3, 6) {
        group = uf.group(val);
        assert(group.size() == 3);
        assert(std::find(group.begin(), group.end(), val) != group.end());
    }

    // [0, 1, 2, 3, 4, 5]
    uf.merge(0, 1);
    uf.merge(2, 3);

    REP3(val, 0, 6) {
        group = uf.group(val);
        assert(group.size() == 6);
        assert(std::find(group.begin(), group.end(), val) != group.end());
    }

    std::cout << "Hello World" << std::endl;
}
