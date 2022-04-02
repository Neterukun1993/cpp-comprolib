#include <vector>


template <typename T>
struct CumulativeSum2D {
    int h, w;
    std::vector<std::vector<T>> cumsum;

    CumulativeSum2D(int h_, int w_)
        : h(h_), w(w_), cumsum(h_ + 1, std::vector<T>(w_ + 1, 0)) {}

    void add(int i, int j, T value) { cumsum[i + 1][j + 1] += value; }

    void build() {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cumsum[i + 1][j + 1] += cumsum[i + 1][j] + cumsum[i][j + 1] - cumsum[i][j];
            }
        }
    }

    T sum(int hl, int hr, int wl, int wr) {
        // sum of values in range [hl, hr) * [wl, wr)
        return cumsum[hr][wr] + cumsum[hl][wl] - cumsum[hr][wl] - cumsum[hl][wr];
    }
};
