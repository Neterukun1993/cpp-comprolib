#pragma once

struct UnionFindWithUndo {
    std::vector<int> parent;
    std::vector<std::pair<int, int>> history;
    int snap;

    UnionFindWithUndo(int n) : parent(n, -1), history(0), snap(0) {}

    void clear() {
        std::fill(parent.begin(), parent.end(), -1);
        history.clear();
        snap = 0;
    }

    int root(int x) {
        if (parent[x] < 0) return x;
        else return root(parent[x]);
    }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        history.emplace_back(x, parent[x]);
        history.emplace_back(y, parent[y]);
        if (x == y) return false;
        if (parent[x] > parent[y]) std::swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }

    int same(int x, int y) { return root(x) == root(y); }

    int size(int x) { return -parent[root(x)]; }

    bool undo() {
        if (history.empty()) return false;
        parent[history.back().first] = history.back().second;
        history.pop_back();
        parent[history.back().first] = history.back().second;
        history.pop_back();
        return true;
    }

    void snapshot() {
        snap = (int)history.size();
    }

    void rollback() {
        while ((int)history.size() > snap) {
            undo();
        }
    }
};