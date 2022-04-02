#include <vector>


template <typename T>
struct BinaryIndexedTree {
    int size;
    std::vector<T> bit;

    BinaryIndexedTree(int n) : size(n + 1), bit(size, 0) {}

    void add(int i, T x) {
        for (int idx = i + 1; idx <= size; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }

    T sum(int r) {
        T res = 0;
        for (int idx = r; idx > 0; idx -= (idx & -idx)) {
            res += bit[idx];
        }
        return res;
    }

    T sum(int l, int r) { return sum(r) - sum(l); }
};
