#pragma once

template <typename T>
struct RangeAddPointGet {
    int size;
    std::vector<T> bit;

    RangeAddPointGet(int n) : size(n + 1), bit(size, 0) {}

    void clear() { std::fill(bit.begin(), bit.end(), 0); }

    void add(int r, T x) {
        for (int idx = r; idx > 0; idx -= (idx & -idx)) {
            bit[idx] += x;
        }
    }

    void add(int l, int r, T x) {
        add(r, x);
        add(l, -x);
    }

    T get(int i) {
        T res = 0;
        for (int idx = i + 1; idx <= size; idx += (idx & -idx)) {
            res += bit[idx];
        }
        return res;
    }
};