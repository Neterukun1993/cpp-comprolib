#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../../src/template/template.hpp"
#include "../../src/data-structure/union-find/union-find-with-undo.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<std::vector<int>>> judges(q + 1);
    std::vector<std::vector<std::vector<int>>> merges(q + 1);

    REP(i, q) {
        int flag, k, u, v;
        std::cin >> flag >> k >> u >> v;
        if (flag == 0) {
            merges[k + 1].emplace_back(std::vector<int>({ i, u, v }));
        }
        if (flag == 1) {
            judges[k + 1].emplace_back(std::vector<int>({ i, u, v }));
        }
    }

    UnionFindWithUndo uf(n);
    std::vector<int> answer(q, -1);

    auto dfs = [&](auto dfs, int k) -> void {
        for (std::vector<int> judge : judges[k + 1]) {
            // グラフ Gk における連結判定を処理する
            int i = judge[0];
            int u = judge[1];
            int v = judge[2];
            answer[i] = uf.same(u, v);
        }
        for (auto merge : merges[k + 1]) {
            // グラフ Gk における辺の追加を処理する
            int i = merge[0];
            int u = merge[1];
            int v = merge[2];
            uf.merge(u, v);
            dfs(dfs, i);
            uf.undo();
        }
    };

    uf.snapshot();
    dfs(dfs, -1);

    REP(i, q) {
        if (answer[i] != -1) std::cout << answer[i] << std::endl;
    }
}