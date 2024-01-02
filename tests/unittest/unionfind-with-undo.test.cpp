#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../src/template/template.hpp"
#include "../../src/data-structure/union-find/union-find-with-undo.hpp"

int main() {
    UnionFindWithUndo uf(4);

    uf.merge(0, 1);
    uf.merge(2, 3);
    assert(uf.same(0, 1));
    assert(uf.same(2, 3));
    assert(!uf.same(0, 2));

    uf.snapshot();
    uf.merge(0, 2);
    assert(uf.same(0, 1));
    assert(uf.same(2, 3));
    assert(uf.same(0, 2));

    uf.rollback();
    assert(uf.same(0, 1));
    assert(uf.same(2, 3));
    assert(!uf.same(0, 2));

    std::cout << "Hello World" << std::endl;
}
