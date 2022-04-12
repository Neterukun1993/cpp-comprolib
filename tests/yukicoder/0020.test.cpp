#define PROBLEM "https://yukicoder.me/problems/no/20"

#include <iostream>
#include <vector>
#include "../../src/graph/grid-dijkstra.hpp"


int main() {
    long long v;
    int n, oj, oi;
    std::cin >> n >> v >> oj >> oi;
    oj -= 1;
    oi -= 1;
    std::vector<std::vector<long long>> l(n, std::vector<long long>(n, 0));
    for (auto& inner : l) {
        for (auto& val : inner) {
            std::cin >> val;
        }
    }

    auto distance = dijkstra(l, 0, 0);

    if (v - distance[n - 1][n - 1] > 0) {
        std::cout << "YES" << std::endl;
        return 0;
    }

    if (oi == -1 && oj == -1) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    if (v - distance[oi][oj] <= 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    v -= distance[oi][oj];
    v *= 2;
    auto mid_distance = dijkstra(l, oi, oj);

    if (v - mid_distance[n - 1][n - 1] > 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
