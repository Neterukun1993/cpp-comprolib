#pragma once

struct UnionFind {
    std::vector<int> parent;
    int cnt;

    UnionFind(int n) : parent(n, -1), cnt(n) {}

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
        cnt -= 1;
        return true;
    }

    int same(int x, int y) { return root(x) == root(y); }

    int size(int x) { return -parent[root(x)]; }

    int count() { return cnt; }
};
