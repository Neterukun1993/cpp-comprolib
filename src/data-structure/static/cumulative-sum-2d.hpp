#pragma once

template <typename T>
struct CumulativeSum2D {
    int h, w;
    std::vector<T> cumsum;

    CumulativeSum2D(int h, int w) : h(h), w(w), cumsum((h + 1) * (w + 1), 0) {}

    void add(int i, int j, T value) { cumsum[(i + 1) * (w + 1) + j + 1] += value; }

    void build() {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cumsum[(i + 1) * (w + 1) + j + 1] += cumsum[(i + 1) * (w + 1) + j] + cumsum[i * (w + 1) + j + 1] - cumsum[i * (w + 1) + j];
            }
        }
    }

    T sum(int hl, int hr, int wl, int wr) {
        // sum of values in range [hl, hr) * [wl, wr)
        return cumsum[hr * (w + 1) + wr] + cumsum[hl * (w + 1) + wl] - cumsum[hr * (w + 1) + wl] - cumsum[hl * (w + 1) + wr];
    }
};