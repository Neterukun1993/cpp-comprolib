#pragma once
#include "../../src/random/xorshift.hpp"

template <typename T>
void shuffle(std::vector<T> &vec) {
    for (int i = (int)vec.size(); i > 1; i--) {
        std::swap(vec[i - 1], vec[rand64() % i]);
    }
}

// [l, r)の範囲をシャッフル
template <typename T>
void shuffle(std::vector<T> &vec, const int l, const int r) {
    assert(l <= r && 0 <= l && r <= (int)vec.size());
    const int d = r - l;
    for (int i = d; i > 1; i--) {
        std::swap(vec[l + i - 1], vec[l + rand64() % i]);
    }
}
