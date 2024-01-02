#pragma once

struct EnumerableUnionFind {
    std::vector<int> parent;
    std::vector<int> next;

    EnumerableUnionFind(int n) : parent(n, -1), next(n) {
        for (int i = 0; i < n; i++) { next[i] = i; }
    }

    void clear() {
        std::fill(parent.begin(), parent.end(), -1);
        for (int i = 0; i < (int)parent.size(); i++) { next[i] = i; }
    }

    int root(int x) {
        if (parent[x] < 0) return x;
        else return parent[x] = root(parent[x]);
    }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (parent[x] > parent[y]) std::swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        std::swap(next[x], next[y]);
        return true;
    }

    int same(int x, int y) { return root(x) == root(y); }

    int size(int x) { return -parent[root(x)]; }

    std::vector<int> group(int x) {
        std::vector<int> result;
        int init = x;
        while (true) {
            result.push_back(x);
            x = next[x];
            if (x == init) break;
        }
        return result;
    }
};