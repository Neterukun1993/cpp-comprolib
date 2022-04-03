#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <iostream>
#include <vector>
#include "../../src/graph/warshall-floyd.hpp"


int main() {
    const long long INF = 1LL << 60;
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<long long>> distance(n, std::vector<long long>(n, INF));
    for (int v = 0; v < n; v++) {
        distance[v][v] = 0LL;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        long long cost;
        std::cin >> u >> v >> cost;
        distance[u][v] = cost;
    }

    warshall_floyd(distance);
    bool negative = false;
    for (int v = 0; v < n; v++) {
        if (distance[v][v] < 0) negative = true;
    }

    if (negative) std::cout << "NEGATIVE CYCLE" << std::endl;
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (distance[i][j] > INF / 1'000) std::cout << "INF" << " ";
                else std::cout << distance[i][j] << " ";
            }
            if (distance[i][n - 1] > INF / 1'000) std::cout << "INF" << std::endl;
            else std::cout << distance[i][n - 1] << std::endl;
        }
    }
}
