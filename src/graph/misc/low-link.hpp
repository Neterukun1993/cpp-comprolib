#pragma once
#include "../graph-template.hpp"

template <typename T>
struct LowLink {
    const Graph<T> &g;
    std::vector<int> used, ord, low;
    std::vector<int> articulation_points;
    std::vector<int> bridges;

    LowLink(const Graph<T> &g) : g(g) {}

    void build() {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);

        int k = 0;
        for (int i = 0; i < (int)g.size(); i++) {
            if (!used[i]) k = dfs(i, k, -1);
        }
        // std::sort(aps.begin(), aps.end());
        // std::sort(briges.begin(), bridges.end(), [](const Edge &a, const Edge &b) {
        //     return a.id < b.id;
        // }
    }

    private:
        int dfs(int id, int k, int par) {
            used[id] = true;
            ord[id] = k++;
            low[id] = ord[id];
            bool is_articulation = false;
            int count = 0;

            for (const auto &e : g[id]) {
                if (!used[e.to]) {
                    count++;
                    k = dfs(e.to, k, id);
                    low[id] = std::min(low[id], low[e.to]);
                    is_articulation |= (par != -1 && ord[id] <= low[e.to]); 
                    if (ord[id] < low[e.to]) bridges.push_back(e.id);
                } else if (e.to != par) {
                    low[id] = std::min(low[id], ord[e.to]);
                }
            }
            if (par == -1 && count > 1) is_articulation = true;
            if (is_articulation) articulation_points.push_back(id);
            return k;
        }
};
