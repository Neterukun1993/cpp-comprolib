#pragma once

template <typename T>
struct CumulativeSum {
    std::vector<T> cumsum;

    CumulativeSum(int n) : cumsum(n + 1, 0) {}

    void add(int i, T value) { cumsum[i + 1] += value; }

    void build() {
        for (int i = 0; i < (int)cumsum.size() - 1; i++) {
            cumsum[i + 1] += cumsum[i];
        }
    }

    T sum(int l, int r) {
        // sum of values in range [l, r)
        return cumsum[r] - cumsum[l];
    }
};