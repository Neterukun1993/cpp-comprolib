#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../src/template/template.hpp"
#include "../../src/random/shuffle.hpp"

void test_all_shuffle() {
    int vec_size = 10;
    int shuffle_count = 1000000;

    std::vector<int> a(vec_size);
    std::vector<std::vector<int>> counter(vec_size, std::vector<int>(vec_size, 0));

    for (int i = 0; i < vec_size; i++) { a[i] = i; }
    for (int try_cnt = 0; try_cnt < shuffle_count; try_cnt++) {
        shuffle(a);
        for (int i = 0; i < vec_size; i++) {
            assert(0 <= a[i] && a[i] < vec_size);
            counter[i][a[i]] += 1;
        }
    }

    for (int i = 0; i < vec_size; i++) {
        for (int j = 0; j < vec_size; j++) {
            assert(shuffle_count / vec_size - 1000 <= counter[i][j] && counter[i][j] <= shuffle_count / vec_size + 1000);
        }
    }
}

void test_range_shuffle() {
    int vec_size = 10;
    int l = 2;
    int r = 7;
    int shuffle_count = 1000000;

    std::vector<int> a(vec_size);
    std::vector<std::vector<int>> counter(vec_size, std::vector<int>(vec_size, 0));

    for (int i = 0; i < vec_size; i++) { a[i] = i; }
    for (int try_cnt = 0; try_cnt < shuffle_count; try_cnt++) {
        shuffle(a, 2, 7);
        for (int i = 0; i < vec_size; i++) {
            assert(0 <= a[i] && a[i] < vec_size);
            counter[i][a[i]] += 1;
        }
    }

    for (int i = 0; i < vec_size; i++) {
        for (int j = 0; j < vec_size; j++) {
            if (l <= i && i < r) {
                if (l <= j && j < r) { assert(2 * shuffle_count / vec_size - 1000 <= counter[i][j] && counter[i][j] <= 2 * shuffle_count / vec_size + 1000); }
                else { assert(counter[i][j] == 0); }
            } else {
                if (i == j) { assert(counter[i][j] == shuffle_count); }
                else { assert(counter[i][j] == 0); }
            }   
        }
    }
}

int main() {
    test_all_shuffle();
    test_range_shuffle();
    std::cout << "Hello World" << std::endl;
}
