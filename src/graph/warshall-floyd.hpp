#include <vector>


void warshall_floyd(std::vector<std::vector<long long>> &distance) {
    int n = distance.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
}
