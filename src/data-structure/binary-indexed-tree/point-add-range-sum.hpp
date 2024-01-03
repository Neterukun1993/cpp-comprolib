#pragma once

template <typename T>
struct PointAddRangeSum {
    int size;
    std::vector<T> bit;

    PointAddRangeSum(int n) : size(n + 1), bit(size, 0) {}

    void clear() { std::fill(bit.begin(), bit.end(), 0); }

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
